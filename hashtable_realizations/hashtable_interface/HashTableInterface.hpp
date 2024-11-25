// Интерфейс для хэш-таблицы
#ifndef __HASHTABLE_INTERFACE__
#define __HASHTABLE_INTERFACE__
#include "constants.hpp"

template<typename HashTableElement, typename Key>
class HashTableInterface {
public:
    virtual HashTableElement& operator [] (Key key) = 0;
private:
    size_t size;
    HashTableElement *Array;
};

#endif