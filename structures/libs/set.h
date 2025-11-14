#pragma once
#include "hashtable.h"
#include <iostream>

class Set {
private:
    HashTable table;

public:
    bool add(int x);
    bool remove(int x);
    bool contains(int x) const;
    void print() const;
    const HashTable::Node* getChainHead(int index) const;
};
