#include "crow.h"

struct CORS
{
    std::string origin;

    CORS(const std::string& origin_) : origin(origin_) {}

    struct context {};

    void before_handle(crow::request& req, crow::response& res, context& ctx)
    {
        // Handle preflight requests
        if (req.method == crow::HTTPMethod::OPTIONS)
        {
            res.code = 204;
            res.add_header("Access-Control-Allow-Origin", origin);
            res.add_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
            res.add_header("Access-Control-Allow-Headers", "Content-Type");
            res.end();
        }
    }

    void after_handle(crow::request& req, crow::response& res, context& ctx)
    {
        res.add_header("Access-Control-Allow-Origin", origin);
        res.add_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
        res.add_header("Access-Control-Allow-Headers", "Content-Type");
    }
};

int main()
{
    crow::App<CORS> app(CORS("*"));

    int counter = 0;

    // Route to get the current count
    CROW_ROUTE(app, "/count")
    ([&counter]() {
        crow::json::wvalue x;
        x["count"] = counter;
        return x;
    });

    // Route to increment the counter
    CROW_ROUTE(app, "/increment")
    .methods("POST"_method)
    ([&counter](const crow::request& req) {
        counter++;
        crow::json::wvalue x;
        x["count"] = counter;
        return x;
    });

    app.port(18080).multithreaded().run();
    return 0;
}
