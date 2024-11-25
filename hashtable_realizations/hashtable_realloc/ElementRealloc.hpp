#ifndef __ELEMENT_REALLOC__
#define __ELEMENT_REALLOC__

template<typename Key, typename Value>
struct ElementRealloc {
    Key key;
    Value value;
    bool is_deleted = false;
};


#endif