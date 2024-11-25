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

template<typename Key, typename Value>
class HashTableRealloc: public HashTable<Key, Value> {
public:
    // add constructors here!!
    ~HashTable() {}
    bool insert(const Key& key, const Value& value) override;
    bool remove(const Key& key) override;

    void clear() override;
    size_t size() const override;
    bool is_contains(const Key& key) override;
    bool is_empty() const override;
    void load_to_file(string path) override;
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

// реализация методов должна быть в том же файле!
