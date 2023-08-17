#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <tuple>

typedef struct {
   std::string key;
   std::string value;
   bool is_deleted = false;
} Record;

typedef std::shared_ptr<Record> record_t;
typedef std::tuple<record_t, error_t> result_t;

class HashTable {
public:
    HashTable(int width, int depth);
    result_t put(std::string key, std::string value);
    result_t get(std::string key, std::string value);
};

#endif