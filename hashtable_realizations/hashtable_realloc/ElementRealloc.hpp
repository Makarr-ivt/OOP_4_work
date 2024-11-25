#pragma once

template<typename Key, typename Value>
struct ElementRealloc {
    Key key;
    Value value;
    bool is_deleted = false;
};
