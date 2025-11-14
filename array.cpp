#include "array.h"

Array::Array() : memory(nullptr), size(0), memorySize(0) {}

Array::~Array() {
    delete[] memory;
}

void Array::resize(int newMemorySize) {
    std::string* newMemory = new std::string[newMemorySize];
    for (int i = 0; i < size; ++i)
        newMemory[i] = memory[i];
    delete[] memory;
    memory = newMemory;
    memorySize = newMemorySize;
}

void Array::add(const std::string& key) {
    if (size >= memorySize) {
        resize(size * 2 + 1);
    }
    memory[size++] = key;
}

std::string Array::get(int index) const {
    if (index < 0 || index >= size) return "";
    return memory[index];
}

int Array::length() const {
    return size;
} 
