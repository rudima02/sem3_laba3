#pragma once
#include <string>
#include <iostream>

class Array {
private:
    std::string* memory;
    int size;
    int memorySize;

    void resize(int newMemorySize);

public:
    Array();
    ~Array();

    void add(const std::string& key);
    std::string get(int index) const;
    int length() const;
};
 
