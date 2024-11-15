#include "crow.h"
#include <asio/asio.hpp>

#include "Mouse.h"
#include "MouseGraphic.h"

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

// int main() {
//     crow::App<CORS> app(CORS("*"));

//     int counter = 0;

//     // Root route to handle requests to "/"
//     CROW_ROUTE(app, "/")
//     ([]() {
//         crow::response response;
//         response.add_header("Access-Control-Allow-Origin", "*");
//         response.add_header("Content-Type", "text/plain");
//         response.write("Welcome to the Crow server!");
//         response.end();
//         return response;
//     });

//     // Route to get the current count
//     CROW_ROUTE(app, "/count")
//     ([&counter]() {
//         crow::json::wvalue x;
//         x["count"] = counter;
//         return x;
//     });

//     // Route to increment the counter
//     CROW_ROUTE(app, "/increment").methods("POST"_method)
//     ([&counter](const crow::request& req) {
//         counter++;
//         crow::json::wvalue x;
//         x["count"] = counter;
//         return x;
//     });

//     app.port(18080).multithreaded().run();
//     return 0;
// }

crow::json::wvalue getMouseGraphics() {
    mms_backend::Mouse mouse;
    mms_backend::MouseGraphic mouseGraphic(&mouse);
    auto triangles = mouseGraphic.draw();

    crow::json::wvalue response;
    for (const auto& triangle : triangles) {
        crow::json::wvalue item;
        item["p1"] = {triangle.p1.x, triangle.p1.y};
        item["p2"] = {triangle.p2.x, triangle.p2.y};
        item["p3"] = {triangle.p3.x, triangle.p3.y};
        item["color"] = {triangle.color.r, triangle.color.g, triangle.color.b};
        item["alpha"] = triangle.alpha;
        response["triangles"].push_back(item);
    }
    return response;
}