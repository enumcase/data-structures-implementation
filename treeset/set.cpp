//
//  set.cpp
//  set
//
//  Created by Margulan Daribayev on 7/8/20.
//  Copyright © 2020 Margulan Daribayev. All rights reserved.
//

#include "set.h"
#include <iostream>



set::treenode* set::copynodes(treenode *original) {
    
    if(original == nullptr) {
        return nullptr;
    }
    
    treenode *copiedTree = new treenode(original->value);
    
    copiedTree->left = copynodes(original->left);
    copiedTree->right = copynodes(original->right);
    
    return copiedTree;
}


void set::deallocatenodes(set::treenode *node) {
    
    if(node != nullptr) {
        deallocatenodes(node->left);
        deallocatenodes(node->right);
        delete node;
    }
    
}

bool set::containshelper(int i, set::treenode *node) {
    
    if (node == nullptr)
       return false;

    // i found
    else if (node->value == i)
       return true;

    // Recursively search for i
    else if (i < node->value)
       return (containshelper(i, node->left));
    
    else
       return (containshelper(i, node->right));
    
}

//bool set::inserthelper(int i, set::treenode *node) {
    
//    if(node == nullptr) {
//        node = new treenode(i);
//        return true;
//    }
//
//    else if(i < node->value) {
//        if(node->left == nullptr) {
//            node->left = new treenode(i);
//            return true;
//        } else {
//            return inserthelper(i, node->left);
//        }
//    }
//
//    else if(i > node->value) {
//        if(node->right == nullptr) {
//            node->right = new treenode(i);
//            return true;
//        } else {
//            return inserthelper(i, node->right);
//        }
//    }
//
//    else {
//        return false;
//    }
    
    
//}


bool set::contains(int i) const {
    
    return containshelper(i, root);
    
}


bool set::insert(int i) {
    
    treenode *temp;
    treenode *parent = nullptr;

    if(root == nullptr) {
        root = new treenode(i);
        temp = root;

    } else {
        temp = root;
        while(temp != nullptr) {
            if(i == temp->value)
                return false;
            else if(i < temp->value) {
                parent = temp;
                temp = temp->left;
            }
            else {
                parent = temp;
                temp = temp->right;
            }
        }

        treenode *toBeInserted = new treenode(i);

        if(i < parent->value)
            parent->left = toBeInserted;
        else
            parent->right = toBeInserted;
    }

    set_size++;
    return true;
    
}


void set::clear() {
    set_size = 0;
    deallocatenodes(root);
    root = nullptr;
}


size_t set::size() const {
    return set_size;
}


bool set::empty() const {
    return (set_size == 0);
}

