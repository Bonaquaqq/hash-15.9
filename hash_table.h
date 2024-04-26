#pragma once

#include <string>
#include <stdexcept>

typedef unsigned int uint;

#define LOAD_FACTOR_THRESHOLD 0.7

class HashTable {
public:
    HashTable();
    ~HashTable();

    void add(const std::string& key, uint* value);
    uint* find(const std::string& key);
    void remove(const std::string& key);

private:
    struct Pair {
        Pair(const std::string& key, uint* value) : key(key), value(value), next(nullptr) {}

        std::string key;
        uint* value;
        Pair* next;
    };

    Pair** array;
    int size;
    int count;

    int hash(const std::string& key);
    int hash_func(const std::string& key, int offset);
    void resize();
};
