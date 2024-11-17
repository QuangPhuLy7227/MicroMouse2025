// #include "crow.h"
// #include "include/asio/asio.hpp"
// #include "include/nlohmann/json.hpp"

// #include "Mouse.h"
// #include "MouseGraphic.h"

// struct CORS {
//     std::string origin;

//     CORS(const std::string& origin_) : origin(origin_) {}

//     struct context {};

//     void before_handle(crow::request& req, crow::response& res, context& ctx) {
//         if (req.method == crow::HTTPMethod::OPTIONS) {
//             res.code = 204;
//             res.add_header("Access-Control-Allow-Origin", origin);
//             res.add_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
//             res.add_header("Access-Control-Allow-Headers", "Content-Type");
//             res.end();
//         }
//     }

//     void after_handle(crow::request& req, crow::response& res, context& ctx) {
//         res.add_header("Access-Control-Allow-Origin", origin);
//         res.add_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
//         res.add_header("Access-Control-Allow-Headers", "Content-Type");
//     }
// };

// // int main() {
// //     crow::App<CORS> app(CORS("*"));

// //     int counter = 0;

// //     // Root route to handle requests to "/"
// //     CROW_ROUTE(app, "/")
// //     ([]() {
// //         crow::response response;
// //         response.add_header("Access-Control-Allow-Origin", "*");
// //         response.add_header("Content-Type", "text/plain");
// //         response.write("Welcome to the Crow server!");
// //         response.end();
// //         return response;
// //     });

// //     // Route to get the current count
// //     CROW_ROUTE(app, "/count")
// //     ([&counter]() {
// //         crow::json::wvalue x;
// //         x["count"] = counter;
// //         return x;
// //     });

// //     // Route to increment the counter
// //     CROW_ROUTE(app, "/increment").methods("POST"_method)
// //     ([&counter](const crow::request& req) {
// //         counter++;
// //         crow::json::wvalue x;
// //         x["count"] = counter;
// //         return x;
// //     });

// //     app.port(18080).multithreaded().run();
// //     return 0;
// // }

// using json = nlohmann::json;

// json getMouseGraphics() {
//     mms_backend::Mouse mouse;
//     mms_backend::MouseGraphic mouseGraphic(&mouse);
//     auto triangles = mouseGraphic.draw();

//     json response;
//     json triangleList = json::array();
//     for (const auto& triangle : triangles) {
//         json triangleItem;

//         triangleItem["p1"] = {
//             {"x", triangle.p1.x},
//             {"y", triangle.p1.y},
//             {"color", {triangle.p1.rgb.r, triangle.p1.rgb.g, triangle.p1.rgb.b}},
//             {"alpha", triangle.p1.a}
//         };
//         triangleItem["p2"] = {
//             {"x", triangle.p2.x},
//             {"y", triangle.p2.y},
//             {"color", {triangle.p2.rgb.r, triangle.p2.rgb.g, triangle.p2.rgb.b}},
//             {"alpha", triangle.p2.a}
//         };
//         triangleItem["p3"] = {
//             {"x", triangle.p3.x},
//             {"y", triangle.p3.y},
//             {"color", {triangle.p3.rgb.r, triangle.p3.rgb.g, triangle.p3.rgb.b}},
//             {"alpha", triangle.p3.a}
//         };

//         triangleList.push_back(triangleItem);
//     }

//     response["triangles"] = triangleList;
//     return response;
// }

// int main() {
//     crow::SimpleApp app;

//     CROW_ROUTE(app, "/mouse")([]() {
//         return getMouseGraphics().dump();
//     });

//     app.port(18080).multithreaded().run();
// }

#include "crow.h"
#include "include/nlohmann/json.hpp"
#include "ColorDialog.h"
#include "Color.h"
#include "crow/middlewares/cors.h"

// struct CORS
// {
//     std::string origin;

//     CORS(const std::string &origin_) : origin(origin_) {}

//     struct context {};

//     void before_handle(crow::request &req, crow::response &res, context &ctx)
//     {
//         if (req.method == crow::HTTPMethod::OPTIONS)
//         {
//             res.code = 204;
//             res.add_header("Access-Control-Allow-Origin", "*");
//             res.add_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
//             res.add_header("Access-Control-Allow-Headers", "Content-Type");
//             res.end();
//         }
//     }

//     void after_handle(crow::request &req, crow::response &res, context &ctx)
//     {
//         res.add_header("Access-Control-Allow-Origin", "*");
//         res.add_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
//         res.add_header("Access-Control-Allow-Headers", "Content-Type");
//     }
// };

using json = nlohmann::json;
using namespace mms_backend;

int main()
{
    crow::SimpleApp app;

    auto& cors = app.get_middleware<crow::CORSHandler>();
    // cors.allow_credentials();

    // Initialize default colors using your mappings from Color.cpp
    char tileBaseColorChar = 'r';
    char tileWallColorChar = 'b';
    char mouseBodyColorChar = 'g';
    char mouseWheelColorChar = 'y';
    char tileWallIsSetColorChar = 'c';
    unsigned char tileWallNotSetAlpha = 128;

    // Create the ColorDialog object with the default colors
    ColorDialog colorDialog(
        tileBaseColorChar,
        tileWallColorChar,
        mouseBodyColorChar,
        mouseWheelColorChar,
        tileWallIsSetColorChar,
        tileWallNotSetAlpha);

    // Print the default colors to verify
    std::cout << "Initial Colors:\n"
              << "Tile Base Color: " << colorDialog.getTileBaseColor() << "\n"
              << "Tile Wall Color: " << colorDialog.getTileWallColor() << "\n"
              << "Mouse Body Color: " << colorDialog.getMouseBodyColor() << "\n"
              << "Mouse Wheel Color: " << colorDialog.getMouseWheelColor() << "\n"
              << "Tile Wall Is Set Color: " << colorDialog.getTileWallIsSetColor() << "\n"
              << "Tile Wall Not Set Alpha: " << static_cast<int>(colorDialog.getTileWallNotSetAlpha()) << std::endl;

    // Register the CORS middleware before defining routes
    // app.middleware<CORS>("http://localhost:3000");
    


    // Define route to get default colors
    CROW_ROUTE(app, "/api/getColors")
    ([&]()
     {
         json response = {
             {"tileBaseColor", std::string(1, colorDialog.getTileBaseColor())},
             {"tileWallColor", std::string(1, colorDialog.getTileWallColor())},
             {"mouseBodyColor", std::string(1, colorDialog.getMouseBodyColor())},
             {"mouseWheelColor", std::string(1, colorDialog.getMouseWheelColor())},
             {"tileWallIsSetColor", std::string(1, colorDialog.getTileWallIsSetColor())},
             {"tileWallNotSetAlpha", colorDialog.getTileWallNotSetAlpha()}
         };
         return crow::response(response.dump());
     });

    // Define route to update colors via React frontend
    CROW_ROUTE(app, "/api/setColors").methods("POST"_method)([&](const crow::request &req)
    {
        try {
            auto data = json::parse(req.body);

            // Log the received data to the console for debugging
            std::cout << "Received data from React:\n" << data.dump(4) << std::endl;

            // Update the ColorDialog object with the new colors
            colorDialog.setColors(
                data["tileBaseColor"].get<char>(),
                data["tileWallColor"].get<char>(),
                data["mouseBodyColor"].get<char>(),
                data["mouseWheelColor"].get<char>(),
                data["tileWallIsSetColor"].get<char>(),
                data["tileWallNotSetAlpha"].get<unsigned char>()
            );

            // Log the updated colors
            std::cout << "Updated colors:\n"
                      << "Tile Base Color: " << colorDialog.getTileBaseColor() << "\n"
                      << "Tile Wall Color: " << colorDialog.getTileWallColor() << "\n"
                      << "Mouse Body Color: " << colorDialog.getMouseBodyColor() << "\n"
                      << "Mouse Wheel Color: " << colorDialog.getMouseWheelColor() << "\n"
                      << "Tile Wall Is Set Color: " << colorDialog.getTileWallIsSetColor() << "\n"
                      << "Tile Wall Not Set Alpha: " << static_cast<int>(colorDialog.getTileWallNotSetAlpha()) << std::endl;

            return crow::response(200);
        } catch (const std::exception &e) {
            std::cerr << "Error parsing request: " << e.what() << std::endl;
            return crow::response(400);
        }
    });

    // Start the Crow server
    app.port(18080).multithreaded().run();

    return 0;
}
