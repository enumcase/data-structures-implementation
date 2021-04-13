//
//  set.cpp
//  HashTableSet
//
//  Created by Margulan Daribayev on 7/13/20.
//  Copyright © 2020 Margulan Daribayev. All rights reserved.
//

#include "set.h"
#include <cctype>
#include <algorithm>

// Case insensitive string equality
bool equal(const std::string& s1, const std::string& s2) {
    
    std::string lowercaseS1 = s1;
    std::string lowercaseS2 = s2;
    
    std::for_each(lowercaseS1.begin(), lowercaseS1.end(),
        [](char & c) {
            c = std::tolower(c);
        }
    );
    
    std::for_each(lowercaseS2.begin(), lowercaseS2.end(),
        [](char & c) {
            c = std::tolower(c);
        }
    );
    
    if(lowercaseS1 == lowercaseS2)
        return true;
    else
        return false;
    
}


    // Hash function
size_t hash(const std::string& s) {
    
    size_t hashcode = 5381;
    for (auto c : s) {
        hashcode = (hashcode << 5) + hashcode + std::tolower(c);
    }
    return hashcode;
    
}


    // Copy constructor
set::set(const set& s):
    bucket_array(new std::list<std::string>[s.bucket_array_size]),
    bucket_array_size(s.bucket_array_size),
    set_size(s.set_size)
{

    for(size_t i=0; i<s.bucket_array_size; i++) {
        bucket_array[i] = s.bucket_array[i];
    }

}

     // Initializer list constructor
set::set(std::initializer_list<std::string> ilist):
    bucket_array(new std::list<std::string>[4]),
    bucket_array_size(4),
    set_size(0)
{    
    for(auto val: ilist) {
        insert(val);
    }
}


    // Copy assignment
set& set::operator=(const set& s) {
    
    if(this != &s) {
        bucket_array_size = s.bucket_array_size;
        set_size = s.set_size;
        delete[] bucket_array;
        bucket_array = new std::list<std::string>[s.bucket_array_size];
        
        for(size_t i=0; i<s.bucket_array_size; i++) {
            bucket_array[i] = s.bucket_array[i];
        }
        
    }
    
    return *this;
}

    // Insert the given value into the set, if it is not already there.
    // Returns true if and only if the value was not already there
bool set::insert(std::string val) {
    
    size_t index = hash(val) % bucket_array_size;
    
    if(!contains(val)) {
        
        bucket_array[index].push_back(val);
        set_size++;
        
        if(loadfactor() > max_load_factor) {
            
            size_t new_bucket_array_size = bucket_array_size * 2;
            std::list<std::string>* new_bucket = new std::list<std::string>[new_bucket_array_size];
            set_size = 0;
            
            std::list<std::string>::iterator it;
            
            for (size_t i = 0; i < bucket_array_size; i++) {
                for(it = bucket_array[i].begin(); it != bucket_array[i].end(); it++) {
                    if(!equal(*it, val)) {
                        size_t new_index = hash(*it) % new_bucket_array_size;
                        new_bucket[new_index].push_back(*it);
                        set_size++;
                    }
                }
            }
            
            size_t val_new_index = hash(val) % new_bucket_array_size;
            new_bucket[val_new_index].push_back(val);
            set_size++;
            
            delete [] bucket_array;
            bucket_array = new_bucket;
            
            bucket_array_size = new_bucket_array_size;
            
        }
        
        return true;
    
    }
    
    return false;
    
}


    // Returns true if and only if the value is in the set
bool set::contains(std::string val) const {
    
    size_t index = hash(val) % bucket_array_size;
    
    std::list<std::string>::iterator it;
    for(it = bucket_array[index].begin(); it != bucket_array[index].end(); it++) {
        if(equal(*it, val)) {
            return true;
        }
    }
    
    return false;
    
}

    // Removes the given value from the set, if it is currently there
    // Returns true if and only if the value was there to be removed
bool set::remove(std::string val) {
    
    size_t index = hash(val) % bucket_array_size;
    
    std::list<std::string>::iterator it;
    for(it = bucket_array[index].begin(); it != bucket_array[index].end(); it++) {
        if(equal(*it, val)) {
            bucket_array[index].erase(it);
            set_size--;
            return true;
        }
    }
    
    return false;
    
}

    // Remove everything from the set
void set::clear() {
    set_size = 0;
}

    // Returns the number of items on the set
size_t set::size() const {
    return set_size;
}

    // Returns whether or not the set is currently empty
bool set::empty() const {
    return (set_size == 0);
}

    // Destructor
set::~set() {
    delete [] bucket_array;
}



