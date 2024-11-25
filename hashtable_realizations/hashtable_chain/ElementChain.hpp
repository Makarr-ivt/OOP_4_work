#pragma once

template<typename Key, typename Value>
struct ElementChain {
    Key key;
    Value value;
    ElementChain *next = nullptr;
};
