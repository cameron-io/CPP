#include "lib/tables/hash_table.hpp"
#include <map>
#include <string>
#include <string.h>
#include <boost/assert.hpp>

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
        assert(table->create_item(item.first, item.second) == 0);
    }

    table->print_table();

    std::string key = "Porsche";
    auto record = table->query_item(key);
    assert(record->value == "Stuttgart, Germany");

    table->delete_item("Dodge");

    try {
        auto record = table->query_item("Dodge");
        throw std::logic_error("item not deleted");
    }
    catch(const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    table->print_table();

    return 0;
}

int main()
{
    return hash_table_test();
}