#pragma once
#include <iostream>
#include <string>

class HashTable {
public:
    struct Node {       
        int key;
        int value;      
        Node* next;
    };

private:
    static const int TABLE_SIZE = 200000;

    int table[TABLE_SIZE];       
    int values[TABLE_SIZE];      
    bool used[TABLE_SIZE];

    Node* chains[TABLE_SIZE];

    int hashOpen(int key) const;
    int hashChain(int key) const;

public:
    HashTable();
    ~HashTable();

    void insertOpen(int key);                  
    void insertOpen(int key, int value);      
    bool searchOpen(int key) const;           
    bool searchOpen(int key, int &value) const; 
    void removeOpen(int key);


    void insertChain(int key);                
    bool searchChain(int key) const;         
    
    void insertChain(int key, int value);
    bool searchChain(int key, int &value) const; 

    void removeChain(int key);

    const Node* getChainHead(int index) const;
    void printChains() const;

    int foldHash(int key) const;

    void printOpen() const;
    void printChain() const;
};

