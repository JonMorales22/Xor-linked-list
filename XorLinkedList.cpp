//
//  XorLinkedList.cpp
//  XOR-Linked-List
//
//  Created by Jonathan Morales on 8/28/18.
//  Copyright © 2018 Jonathan Morales. All rights reserved.
//

#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include "XorLinkedList.h"

XorLinkedList::XorLinkedList() {
    tail = nullptr;
    head = nullptr;
    length = 0;
}

void XorLinkedList::push(int value) {
    if(tail==nullptr&&head==nullptr){
        Node* node = new Node(value, reinterpret_cast<uintptr_t>(tail));
        tail = node;
        head = node;
        length++;
    }
    else {
        Node* node_ptr = new Node(value, reinterpret_cast<uintptr_t>(tail));
        unsigned long addr1 = tail->getNpx();
        unsigned long addr2 = reinterpret_cast<uintptr_t>(node_ptr);
        tail->setNpx(addr1^addr2);
        tail = node_ptr;
        length++;
    }
}

void XorLinkedList::unshift(int value) {
    if(head==nullptr) {
        Node* node_ptr = new Node(value, reinterpret_cast<uintptr_t>(tail));
        tail = node_ptr;
        head = node_ptr;
        length++;
    }
    else {
        Node* node_ptr = new Node(value, reinterpret_cast<uintptr_t>(head));
        head->setNpx(head->getNpx() ^ reinterpret_cast<uintptr_t>(node_ptr));
        head = node_ptr;
    }
}

void XorLinkedList::add(int value, int index) {
    Node* node_ptr, *node_ptr2, *temp_ptr;
    
    if(index<0)
       throw "Index is less than 0!";
    else if(index==0) {
        unshift(value);
        return;
    }
    else if(index>length-1){
        push(value);
        return;
    }
    
    node_ptr = (Node *) head->getNpx();
    node_ptr2 = head;
    
    int counter = 0;
    while(node_ptr!=nullptr) {
        if(counter==index-1) {
            temp_ptr = new Node(value, reinterpret_cast<uintptr_t>(node_ptr) ^ reinterpret_cast<uintptr_t>(node_ptr2));
            node_ptr->setNpx(node_ptr->getNpx() ^ reinterpret_cast<uintptr_t>(node_ptr2) ^ reinterpret_cast<uintptr_t>(temp_ptr));
            node_ptr2->setNpx(node_ptr2->getNpx() ^ reinterpret_cast<uintptr_t>(node_ptr) ^ reinterpret_cast<uintptr_t>(temp_ptr));
            return;
        }
        temp_ptr = node_ptr2;
        node_ptr2 = node_ptr;
        node_ptr = (Node*) (node_ptr->getNpx() ^ reinterpret_cast<uintptr_t>(temp_ptr));
        counter++;
    }
}

void XorLinkedList::traverse(int direction) {
    Node* node_ptr, *node_ptr2;
    
    if(length<=0)
        return;
    else if(direction == 0){
        node_ptr = (Node *) head->getNpx();
        node_ptr2 = head;
    }
    else if(direction == 1) {
        node_ptr = (Node *) tail->getNpx();
        node_ptr2 = tail;
    }
    else
        return;
    
    while(node_ptr!=nullptr) {
        std::cout << "data: " << node_ptr2->getData() << "\n";
        Node* temp_ptr = node_ptr2;
        node_ptr2=node_ptr;
        node_ptr = (Node*) (node_ptr->getNpx() ^ reinterpret_cast<uintptr_t>(temp_ptr));
    }
    std::cout << "data: " << node_ptr2->getData() << "\n";
}

void XorLinkedList::traverse(int direction, int index) {
    Node* node_ptr, *node_ptr2;
    int counter = 0;
    
    if(direction == 0){
        node_ptr = (Node *) head->getNpx();
        node_ptr2 = head;
    }
    else if(direction == 1) {
        node_ptr = (Node *) tail->getNpx();
        node_ptr2 = tail;
    }
    else
        return;
    
    counter = 0;
    while(node_ptr!=nullptr) {
        std::cout << "data: " << node_ptr2->getData() << "\n";
        Node* temp_ptr = node_ptr2;
        node_ptr2 = node_ptr;
        node_ptr = (Node*) (node_ptr->getNpx() ^ reinterpret_cast<uintptr_t>(temp_ptr));
        counter++;
        if(counter >= index)
            return;
    }
    std::cout << "data: " << node_ptr2->getData() << "\n";
}

int XorLinkedList::remove(int index) {
    Node* node_ptr, *node_ptr2, *temp_ptr;
    
    if(index < 0 || index > length-1)
        return -1;
    else if(index==0)
        return shift();
    else if(index==length-1)
        return pop();
    
    node_ptr = (Node *) head->getNpx();
    node_ptr2 = head;
    
    int counter = 0;
    while(node_ptr!=nullptr) {
        if(counter==index-1) {
            temp_ptr = node_ptr;
            node_ptr = (Node*) (node_ptr->getNpx() ^ reinterpret_cast<uintptr_t>(node_ptr2));
            
            node_ptr->setNpx(node_ptr->getNpx() ^ reinterpret_cast<uintptr_t>(temp_ptr) ^ reinterpret_cast<uintptr_t>(node_ptr2));
            node_ptr2->setNpx(node_ptr2->getNpx() ^ reinterpret_cast<uintptr_t>(temp_ptr) ^ reinterpret_cast<uintptr_t>(node_ptr));
            break;
        }
        temp_ptr = node_ptr2;
        node_ptr2 = node_ptr;
        node_ptr = (Node*) (node_ptr->getNpx() ^ reinterpret_cast<uintptr_t>(temp_ptr));
        counter++;
    }
    
    int value = temp_ptr->getData();
    delete temp_ptr;
    return value;
}

int XorLinkedList::pop() {
    
    if(length<=0){
        return -1;
    }
    else if(length==1){
        int value = head->getData();
        delete head;
        return value;
    }
    
    Node* node_ptr, *temp_ptr;
    node_ptr = (Node *) tail->getNpx();
    temp_ptr = tail;
    node_ptr->setNpx(node_ptr->getNpx() ^  reinterpret_cast<uintptr_t>(tail));
    tail = node_ptr;
   
    int value = temp_ptr->getData();
    delete temp_ptr;
    return value;
}

int XorLinkedList::shift() {
    
    if(length<=0){
        return -1;
    }
    else if(length==1){
        int value = head->getData();
        delete head;
        return value;
    }
    
    Node* node_ptr, *temp_ptr;
    node_ptr = (Node *) head->getNpx();
    temp_ptr = head;
    node_ptr->setNpx(node_ptr->getNpx() ^  reinterpret_cast<uintptr_t>(head));
    head = node_ptr;
    
    int value = temp_ptr->getData();
    delete temp_ptr;
    return value;
}

