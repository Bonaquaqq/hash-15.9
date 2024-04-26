
#include <functional>
#include "hash_table.h"

HashTable::HashTable() {
    size = 10; // Initial size of the array
    count = 0;
    array = new Pair * [size]();
}

HashTable::~HashTable() {
    for (int i = 0; i < size; ++i) {
        Pair* current = array[i];
        while (current != nullptr) {
            Pair* next = current->next;
            delete current;
            current = next;
        }
    }
    delete[] array;
}

void HashTable::add(const std::string& key, uint* value) {
    if (find(key) != nullptr) {
        throw std::invalid_argument("Key already exists");
    }

    int index = hash(key);

    if (array[index] == nullptr) {
        array[index] = new Pair(key, value);
    }
    else {
        Pair* current = array[index];
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Pair(key, value);
    }

    count++;

    if (count >= size * LOAD_FACTOR_THRESHOLD) {
        resize();
    }
}

uint* HashTable::find(const std::string& key) {
    int index = hash(key);
    Pair* current = array[index];
    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return nullptr;
}

void HashTable::remove(const std::string& key) {
    int index = hash(key);
    if (array[index] == nullptr) {
        throw std::invalid_argument("Key not found");
    }
    Pair* current = array[index];
    Pair* prev = nullptr;
    while (current != nullptr && current->key != key) {
        prev = current;
        current = current->next;
    }
    if (current == nullptr) {
        throw std::invalid_argument("Key not found");
    }
    if (prev == nullptr) {
        array[index] = current->next;
    }
    else {
        prev->next = current->next;
    }
    delete current;
    count--;
}

int HashTable::hash(const std::string& key) {
    int sum = 0;
    for (char c : key) {
        sum += c;
    }
    return sum % size;
}

int HashTable::hash_func(const std::string& key, int offset) {
    return (hash(key) + offset * offset) % size;
}

void HashTable::resize() {
    int newSize = size * 2;
    Pair** newArray = new Pair * [newSize]();
    for (int i = 0; i < newSize; ++i) {
        newArray[i] = nullptr;
    }

    for (int i = 0; i < size; ++i) {
        Pair* current = array[i];
        while (current != nullptr) {
            Pair* next = current->next;
            int newIndex = hash(current->key) % newSize;
            current->next = newArray[newIndex];
            newArray[newIndex] = current;
            current = next;
        }
    }

    for (int i = 0; i < size; ++i) {
        Pair* current = array[i];
        while (current != nullptr) {
            Pair* next = current->next;
            delete current;
            current = next;
        }
    }

    delete[] array;
    array = newArray;
    size = newSize;
}
