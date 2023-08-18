#include "lib/tables/hash_table.hpp"

#include <map>
#include <string>

int hash_table_test()
{
    int width = 10;
    int depth = 5;

    auto table = std::make_shared<HashTable>(width, depth);

    std::map<std::string, std::string> items {
        {"Dodge", "Auburn Hills, Michigan"},
        {"Ford", "Dearborn, Michigan"},
        {"Chevrolet", "Detroit, Michigan"},
        {"Ferrari", "Maranello, Italy"},
        {"Lamborghini", "Bolognese, Italy"},
        {"Porsche", "Stuttgart, Germany"}
    };

    for (const auto& item : items) {
        if (table->create_item(item.first, item.second) != 0)
            throw std::logic_error("unable to insert item");
    }

    table->print_table();

    std::string key1 = "Porsche";
    auto record1 = table->query_item(key1);
    if (record1->value != "Stuttgart, Germany")
        throw std::logic_error("item query assertion failed");

    return 0;
}

int main()
{
    return hash_table_test();
}