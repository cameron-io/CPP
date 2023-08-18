#include "hash_table.hpp"

int hash(std::string key, int width)
{
   return key.size() % width;
}

/*
    width -> number of buckets
    depth -> bucket-depth
*/
HashTable::HashTable(int width, int depth)
{
    this->width = width;
    this->depth = depth;
    this->table = std::vector<std::vector<record_t>>(width);
}

int HashTable::create(std::string key, std::string value)
{
    const int bucketIndex = hash(key, this->width);
    auto& bucket = this->table[bucketIndex];
    record_t newObj = std::make_shared<Record>(key, value);

    auto it = std::find_if(
        bucket.begin(), 
        bucket.end(), 
        [](const auto record) -> bool {
            return record->is_deleted == true;
    });
    if (it != bucket.end()) {
        int index = it - bucket.begin();
        bucket[index] = newObj;
        return 0;
    } else {
        return 1;
    }
}

int HashTable::update(std::string key, std::string value)
{
    const int bucketIndex = hash(key, this->width);
    auto& bucket = this->table[bucketIndex];
    record_t newObj = std::make_shared<Record>(key, value);

    auto it = std::find_if(
        bucket.begin(), 
        bucket.end(), 
        [key](const auto record) -> bool {
            return record->key == key;
        }
    );

    if (it != bucket.end()) {
        int index = it - bucket.begin();
        bucket[index] = newObj;
    } else {
        return 1;
    }

    return 0;
}

record_t HashTable::query(std::string key)
{
    const int bucketIndex = hash(key, this->width);
    auto& bucket = this->table[bucketIndex];
    
    auto it = std::find_if(
        bucket.begin(), 
        bucket.end(), 
        [key](const auto record) -> bool {
            return record->key == key;
        }
    );

    if (it != bucket.end()) {
        int index = it - bucket.begin();
        return bucket[index];
    }

    return std::make_shared<Record>("", "");;
}

void HashTable::print_table() {
    std::cout << "[\n";
    for (int w = 0; w < this->width; w++)
    {
        auto bucket = this->table[w];
        std::cout << "    [";
        std::for_each(
            bucket.begin(), 
            bucket.end(),
            [](record_t record) {
                if (record->is_deleted != true) {
                    std::cout << "\033[1;36m{" << record->key << ": " <<  record->value << "}\033[0m";
                } else {
                    std::cout << "nil";
                }
            } 
        );
        std::cout << "]\n";
    }
    std::cout << "]" << std::endl;
}
