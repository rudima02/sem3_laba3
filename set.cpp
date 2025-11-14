#include "set.h"

bool Set::add(int x) {
    if (!contains(x)) { 
        table.insertChain(x); 
        return true;
    }
    return false;
}

bool Set::remove(int x) {
    if (contains(x)) { 
        table.removeChain(x);
        return true; 
    }
    return false;
}

bool Set::contains(int x) const {
    return table.searchChain(x);
}

void Set::print() const {
    std::cout << "{ ";
    const int TABLE_SIZE = 1000;
    for (int i = 0; i < TABLE_SIZE; ++i) {
        const HashTable::Node* node = table.getChainHead(i);
        while (node) {
            std::cout << node->key << " ";
            node = node->next;
        }
    }
    std::cout << "}\n";
}

const HashTable::Node* Set::getChainHead(int index) const {
    return table.getChainHead(index);
}
