#include "hash_table.hpp"

int hash(std::string key, int width)
{
   return key.size() % width;
}

class HashTable {
    int width = 0;
    std::vector<std::vector<std::shared_ptr<Record>>> table;

    public:
    /*
        width = buckets_num
        depth = buckets_depth
    */
    HashTable(int width, int depth)
    {
        this->width = width;
        this->table = std::vector<std::vector<std::shared_ptr<Record>>>(
            depth,
            std::vector<std::shared_ptr<Record>>(width)
        );
    }

    result_t put(std::string key, std::string value)
    {
        const int bucketIndex = hash(key, this->width);
        auto& bucket = this->table[bucketIndex];
        std::shared_ptr<Record> newObj = std::make_shared<Record>(key, value);

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
            bucket.push_back(newObj);
        }

        return std::make_tuple(newObj, 0);
    }

    result_t get(std::string key, std::string value)
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
            return std::make_tuple(bucket[index], 0);
        }
    }
};
