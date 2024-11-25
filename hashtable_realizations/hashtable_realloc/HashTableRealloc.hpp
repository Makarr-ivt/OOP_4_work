/**
 * Хэш таблица, реализующая открытую адресацию:
 * Массив хранит сами пары "ключ: значение";
 * При коллизии хэш функция обходит массив
 * в поисках свободного места;
 * когда свободные места заполняются,
 * выделяется массив большего объёма,
 * все старые актуальные значения копируются.
 */
#ifndef __HASHTABLE_REALLOC__
#define __HASHTABLE_REALLOC__
#include "HashTableInterface.hpp"
#include "ElementRealloc.hpp"

template<typename Key, typename Value>
class HashTableRealloc: public HashTable {
private:
    size_t size;
    size_t capacity;
    ElementRealloc* array;
};



#endif