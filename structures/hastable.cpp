#include "hashtable.h"
#include <algorithm>

HashTable::HashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        table[i] = 0;
        values[i] = 0;
        used[i] = false;
        chains[i] = nullptr;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        Node* node = chains[i];
        while (node) {
            Node* tmp = node;
            node = node->next;
            delete tmp;
        }
    }
}

int HashTable::hashOpen(int key) const { return key % TABLE_SIZE; }
int HashTable::hashChain(int key) const { return key % TABLE_SIZE; }

void HashTable::insertOpen(int key) {
    int idx = hashOpen(key);
    while (used[idx]) idx = (idx + 1) % TABLE_SIZE;
    table[idx] = key;
    used[idx] = true;
}

void HashTable::insertOpen(int key, int value) {
    int idx = hashOpen(key);
    int start = idx;
    while (used[idx]) {
        if (table[idx] == key) { 
            values[idx] = value;
            return;
        }
        idx = (idx + 1) % TABLE_SIZE;
        if (idx == start) return; 
    }
    table[idx] = key;
    values[idx] = value;
    used[idx] = true;
}


bool HashTable::searchOpen(int key) const {
    int idx = hashOpen(key), start = idx;
    while (used[idx]) {
        if (table[idx] == key) return true;
        idx = (idx + 1) % TABLE_SIZE;
        if (idx == start) break;
    }
    return false;
}

bool HashTable::searchOpen(int key, int &value) const {
    int idx = hashOpen(key), start = idx;
    while (used[idx]) {
        if (table[idx] == key) {
            value = values[idx];
            return true;
        }
        idx = (idx + 1) % TABLE_SIZE;
        if (idx == start) break;
    }
    return false;
}

void HashTable::removeOpen(int key) {
    int idx = hashOpen(key), start = idx;
    while (used[idx]) {
        if (table[idx] == key) {
            used[idx] = false;
            return;
        }
        idx = (idx + 1) % TABLE_SIZE;
        if (idx == start) break;
    }
}

void HashTable::insertChain(int key) {
    int idx = hashChain(key);
    Node* node = chains[idx];
    while (node) {
        if (node->key == key) return;
        node = node->next;
    }
    Node* newNode = new Node{key, 0, chains[idx]};
    chains[idx] = newNode;
}

void HashTable::insertChain(int key, int value) {
    int idx = hashChain(key);
    Node* node = chains[idx];
    while (node) {
        if (node->key == key) {
            node->value = value;
            return;
        }
        node = node->next;
    }
    Node* newNode = new Node{key, value, chains[idx]};
    chains[idx] = newNode;
}

bool HashTable::searchChain(int key) const {
    int idx = hashChain(key);
    Node* node = chains[idx];
    while (node) {
        if (node->key == key) return true;
        node = node->next;
    }
    return false;
}

bool HashTable::searchChain(int key, int &value) const {
    int idx = hashChain(key);
    Node* node = chains[idx];
    while (node) {
        if (node->key == key) {
            value = node->value;
            return true;
        }
        node = node->next;
    }
    return false;
}

void HashTable::removeChain(int key) {
    int idx = hashChain(key);
    Node* node = chains[idx];
    Node* prev = nullptr;
    while (node) {
        if (node->key == key) {
            if (prev) prev->next = node->next;
            else chains[idx] = node->next;
            delete node;
            return;
        }
        prev = node;
        node = node->next;
    }
}

const HashTable::Node* HashTable::getChainHead(int index) const {
    if (index < 0 || index >= TABLE_SIZE) return nullptr;
    return chains[index];
}

void HashTable::printChains() const {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        Node* node = chains[i];
        if (node) {
            std::cout << "[" << i << "]: ";
            while (node) {
                std::cout << node->key << "->" << node->value << " ";
                node = node->next;
            }
            std::cout << "nullptr\n";
        }
    }
}

int HashTable::foldHash(int key) const {
    std::string s = std::to_string(key);
    int sum = 0;
    for (size_t i = 0; i < s.size(); i += 3) {
        int part = 0;
        size_t end = std::min(s.size(), i + 3);
        for (size_t j = i; j < end; ++j)
            part = part * 10 + (s[j] - '0');
        sum += part;
    }
    return sum;
}

void HashTable::printOpen() const {
    std::cout << "Хеш таблица:\n";
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (used[i]) {
            std::cout << "[" << i << "] -> Key: " << table[i] << "\n";
        }
    }
}

void HashTable::printChain() const {
    std::cout << "Метод простых цепочек:\n";
    for (int i = 0; i < TABLE_SIZE; ++i) {
        Node* node = chains[i];
        if (node) {
            std::cout << "[" << i << "]: ";
            while (node) {
                std::cout << node->key << " -> " << node->value << "  ";
                node = node->next;
            }
            std::cout << "nullptr\n";
        }
    }
}
