// Интерфейс для хэш-таблицы
#ifndef __HASHTABLE_INTERFACE__
#define __HASHTABLE_INTERFACE__
#include "constants.hpp"
#include <string>
using namespace std;

template<typename Key, typename Value>
class HashTable {
public:
    virtual ~HashTable() {}
    virtual bool insert(const Key& key, const Value& value) = 0;
    virtual bool remove(const Key& key) = 0;

    virtual void clear() = 0;
    virtual size_t size() const = 0;
    virtual bool is_contains(const Key& key) = 0;
    virtual bool is_empty() const = 0;
    virtual load_to_file(string path) = 0;
    virtual read_from_file(string path) = 0;

    virtual Value& operator[](const Key& key) = 0;
    virtual bool operator==(const HashTable& other) const = 0;
    virtual HashTable& operator&&(const HashTable& other) = 0;
};

#endif