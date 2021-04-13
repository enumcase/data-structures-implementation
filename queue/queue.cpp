#include "queue.h"
#include <iostream>
#include <stdexcept>


queue::queue(const queue& q):
    queue_size(q.queue_size)
{
    if(q.front == nullptr) {
        front = back = nullptr; //basically empty queue
    }
    
    node *temp = new node(q.front->value);
    front = temp;
    
    //loop to copy all of q's nodes into the queue
    for (node *toCopy = q.front; toCopy->next != nullptr; toCopy = toCopy->next) {
        temp->next = new node(toCopy->next->value);
        temp = temp->next;
    }
    
    temp->next = nullptr;
    
}


queue::queue(std::initializer_list<int> ilist):
    queue_size(ilist.size()),
    front(nullptr),
    back(nullptr)
{
    
    //pushing algorithm ≈ push(val) - but without increasing the queue_size
    for(int val : ilist) {
        
        node* newLink = new node(val);
           
        if(front == nullptr) {
            front = back = newLink;
        }
           
        back = back->next = newLink;
        
    }
    
}


queue& queue::operator=(const queue& q) {
    
    if(this != &q) {
        
        if (q.empty()) return *this;
        
        //clearing the queue
        while(!empty()) {
            node *toRemove = front;
            front = front->next;
            delete toRemove;
        
            
            if(front == nullptr) {
                back = nullptr;
            }
        }
        
        queue_size = q.queue_size;
        
        delete front;
        front = new node(q.front->value);
        node *temp = q.front->next;
        node *toCopy = front;
        
        //copying q's nodes into the queue
        while(temp != nullptr) {
            toCopy = toCopy->next = new node(temp->value);
            temp = temp->next;
        }
        
        back = toCopy;
        
    }
    
    return *this;
}


void queue::push(int val) {
    
    node* newLink = new node(val);
    
    if(empty()) {
        front = back = newLink;
    }
    
    back = back->next = newLink;
    
    queue_size++;
}


int queue::peek() const {
    
    if(empty()) {
        throw std::runtime_error("Queue is empty! Can not peek front-most item.\n");
    }
    
    return front->value;
}


void queue::pop() {
    
    if(empty()) {
        throw std::runtime_error("Queue is empty! Can not pop front-most item from it.\n");
    }
    
    node *toRemove = front;
    front = front->next;
    delete toRemove;
    
    if(front == nullptr) {
        back = nullptr;
    }
    
    queue_size--;
    
}


void queue::clear() {
    
    while(!empty()) {
        
        if(front == nullptr) {
            back = nullptr;
            break;
        }
        
        node *toRemove = front;
        front = front->next;
        delete toRemove;
        
    }
    
    queue_size = 0;
}


size_t queue::size() const {
    return queue_size;
}


bool queue::empty() const {
    return (queue_size == 0);
}


queue::~queue() {
    
    node* temp = front;
    node* prev = temp;
    
    while(temp != nullptr) {
        prev = temp->next;
        delete temp;
        temp = prev;
    }
}
