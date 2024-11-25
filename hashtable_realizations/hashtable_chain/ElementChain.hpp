#ifndef __ELEMENT_CHAIN__
#define __ELEMENT_CHAIN__

template<typename Key, typename Value>
struct ElementChain {
    Key key;
    Value value;
    ElementChain *next = nullptr;
};


#endif