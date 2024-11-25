/**
 * Хэш таблица, реализующая открытую адресацию:
 * Массив хранит сами пары "ключ: значение";
     * При коллизии хэш функция обходит массив
 * в поисках свободного места;
 * когда свободные места заполняются,
 * выделяется массив большего объёма,
 * все старые актуальные значения копируются.
 */
#pragma once
#include "HashTableInterface.hpp"
#include "ElementRealloc.hpp"
#include <functional> // std::hash
using namespace std;

template<typename Key, typename Value>
class HashTableRealloc: public HashTable<Key, Value> {
public:
    HashTableRealloc(): size(0), capacity(START_CAPACITY){
        ElementRealloc* array = new ElementRealloc(START_CAPACITY);
        for (int i; i < capacity; ++i) {
            array[i] = nullptr;
        }
    };
    HashTableRealloc(const HashTableRealloc& other): size(other.size), capacity(other.capacity){
        for (int i = 0; i < size; ++i)
            if (other.array[i]){
                array[i] = other.array[i];
            } else { 
                array[i] = nullptr;
            }
        };
    ~HashTableRealloc() {
        for (int i = 0; i < size; ++i)
            if (array[i])
                delete array[i];
        delete[] array;
    };
    void insert(const Key& key, const Value& value) override;
    bool remove(const Key& key) override;

    void clear() override;
    size_t get_size() const override;
    bool is_contains(const Key& key) const override;
    bool is_empty() const override;
    void load_to_file(string path) const override;
    bool read_from_file(string path) override;

    Value& operator[](const Key& key) override;
    bool operator==(const HashTable& other) const override;
    HashTable& operator&&(const HashTable& other) override;
    
private:
    size_t size;
    size_t capacity;
    ElementRealloc* array;
    void arrayRealloc();
};


template<typename Key, typename Value>
void HashTableRealloc<Key, Value>::arrayRealloc() {
    ElementRealloc* oldArray = new ElementRealloc(size);
    copy_n(array, size, oldArray);
    array = new ElementRealloc(capacity * 2);
    copy_n(oldArray, size, array);
    delete[] oldArray;
}


template<typename Key, typename Value>
size_t HashTableRealloc<Key, Value>::get_size() const {
    return size;
}

template<typename Key, typename Value>
void HashTableRealloc<Key, Value>::insert(const Key& key, const Value& value) {
    size_t index = hash<Key>(key) % size;
    for (int i = 0; i < size; ++i) {
        if (array[(index+i)%size] == nullptr) {
            array[(index+i)%size] = ElementRealloc(key, value);
            ++size;
            return;
        } else if (array[(index+i)%size].key == key) {
            array[(index+i)%size].value = value;
            array[(index+i)%size].is_deleted = false;
            return;
        }
    };
    if (size * REALLOC_FACTOR > capacity * 100) {
        arrayRealloc();
    }
}


// реализация методов должна быть в том же файле!
