#include "stack.h"

Stack::Stack(int cap) : top(nullptr), capacity(cap) {}

Stack::~Stack() {
    clear();
}

void Stack::push(int val) {
    Node* node = new Node{val, top};
    top = node;
}

int Stack::pop() {
    if (isEmpty()) throw std::underflow_error("Stack underflow");
    Node* temp = top;
    int val = top->value;
    top = top->next;
    delete temp;
    return val;
}

int Stack::peek() const {
    if (isEmpty()) throw std::underflow_error("Stack empty");
    return top->value;
}

bool Stack::isEmpty() const {
    return top == nullptr;
}

void Stack::clear() {
    while (!isEmpty()) pop();
}
 
