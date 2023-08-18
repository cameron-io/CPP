#include "lib/tables/hash_table.hpp"

int hash_table_test()
{
    auto table = std::make_shared<HashTable>(10, 5);

    table->create("Dodge", "Auburn Hills, Michigan");
    table->create("Ford", "Dearborn, Michigan");
    table->create("Chevrolet", "Detroit, Michigan");
    table->create("Ferrari", "Maranello, Italy");
    table->create("Lamborghini", "Bolognese, Italy");
    table->create("Porsche", "Stuttgart, Germany");

    table->print_table();

    // Query Bucket Collision
    std::string key1 = "Porsche";
    record_t record1 = table->query(key1);
    std::cout << "Record " << key1 << " query  : " << record1->value << std::endl;

    std::string key2 = "Dodge";
    record_t record2 = table->query(key2);
    std::cout << "Record " << key2 << " query  : " << record2->value << std::endl;

    table->print_table();

    return 0;
}

int main()
{
    return hash_table_test();
}