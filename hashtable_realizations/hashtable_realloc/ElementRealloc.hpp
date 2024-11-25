#pragma once

template<typename Key, typename Value>
struct ElementRealloc {
    Key key;
    Value value;
    bool is_deleted = false;
    ElementRealloc(const Key& k, const Value& v) : key(k), value(v) {};
    ElementRealloc(const ElementRealloc& other): ElementRealloc(other.key, other.value) {
        is_deleted(other.is_deleted);
    };
};
