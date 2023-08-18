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
    this->table = std::vector<std::vector<record_t>>(
        width,
        std::vector<record_t>(
            depth,
            std::make_shared<Record>("", "")
        )
    );
}

int HashTable::create_item(std::string key, std::string value)
{
    if (key == "") throw std::invalid_argument("key cannot be empty");

    const int bucket_index = hash(key, this->width);
    auto& bucket = this->table[bucket_index];
    record_t record = std::make_shared<Record>(key, value);

    int i = 0;
    while (bucket[i]->key != "")
        i++;

    if (i != this->width) {
        this->table[bucket_index][i] = record;
        return 0;
    } else {
        this->table[bucket_index].push_back(record);
        this->depth++;
        return 0;
    }
}

int HashTable::update_item(std::string key, std::string value)
{
    if (key == "") throw std::invalid_argument("key cannot be empty");

    const int bucket_index = hash(key, this->width);
    auto& bucket = this->table[bucket_index];
    record_t record = std::make_shared<Record>(key, value);

    int i = 0;
    while (bucket[i]->key != "")
        i++;
    if (i != this->width) {
        this->table[bucket_index][i] = record;
        return 0;
    } else {
        return 1;
    }
}

record_t HashTable::query_item(std::string key)
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

    throw std::invalid_argument("item not found");
}

void HashTable::print_table() {
    std::cout << "[\n";
    for (const auto w : this->table)
    {
        std::cout << "    [";
        for (const auto record : w) {
            if (record->is_deleted != true) {
                std::cout << "{" << record->key << ": " <<  record->value << "}";
            } else {
                std::cout << "nil";
            }
        }
        std::cout << "]\n";
    }
    std::cout << "]" << std::endl;
}
