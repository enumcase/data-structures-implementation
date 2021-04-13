#include "stack.h"
#include <stdexcept>
#include <iostream>


stack::stack(const stack& stk):
    values(new int[stk.array_capacity]),
    stack_size(stk.stack_size),
    array_capacity(stk.array_capacity)
{
    
    for(size_t i=0; i<stk.stack_size; i++){
        values[i] = stk.values[i];
    }
    
}
    

stack::stack(std::initializer_list<int> ilist):
    values(new int[ilist.size()]),
    stack_size(ilist.size()),
    array_capacity(ilist.size())
{
    
    size_t i = 0;
    
    for(int val : ilist) {
        values[i] = val;
        ++i;
    }
    
}

    
stack& stack::operator=(const stack& stk) {
    
    if(stack_size != stk.stack_size) {
        stack_size = stk.stack_size;
        array_capacity = stk.array_capacity;
        delete [] values;
        values = new int[stk.array_capacity];
    }
    
    for(size_t i=0; i<stk.stack_size; i++) {
        values[i] = stk.values[i];
    }
    
    return *this;
}

    
void stack::push(int val) {
    
    if(stack_size == array_capacity) {
        array_capacity *= 2;
        int *new_values = new int[array_capacity];

        for(size_t i=0; i<stack_size; i++){
            new_values[i] = values[i];
        }

        delete [] values;
        values = new_values;
    }
    
    values[stack_size] = val;
    ++stack_size;
}
    

int stack::peek() const {
    
    if(empty()) {
        throw std::runtime_error("Stack is empty! Can not peek top of stack.\n");
    }
    
    return values[stack_size-1];
}
    
    
void stack::pop() {
    
    if(empty()) {
        throw std::runtime_error("Stack is empty! Can not pop an item from it.\n");
    }
    
    stack_size--;
}
    
    
void stack::clear() {
    stack_size = 0;
}
    

size_t stack::size() const {
    return stack_size;
}

    
bool stack::empty() const {
    return (stack_size == 0);
}
    

stack::~stack() {
    delete [] values;
}
    
