#pragma once
#include <stdexcept>

struct Node {
    int value;
    Node* next;
};

class Stack {
private:
    Node* top;
    int capacity; 

public:
    Stack(int capacity = 1000); 
    ~Stack();

    void push(int val);
    int pop();
    int peek() const;
    bool isEmpty() const;
    void clear();
};
 
