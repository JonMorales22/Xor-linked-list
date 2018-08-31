//
//  XorLinkedList.h
//  XOR-Linked-List
//
//  Created by Jonathan Morales on 8/28/18.
//  Copyright © 2018 Jonathan Morales. All rights reserved.
//

#ifndef XorLinkedList_h
#define XorLinkedList_h
#include "Node.h"


#endif /* XorLinkedList_h */
class XorLinkedList {
public:
    XorLinkedList();
    void traverse(int direction);
    void traverse(int direction, int index);
    void add(int value);
    void add(int value, int index);
    void unshift(int value);
    int pop();
    int shift();
    int remove(int index);
    Node* getTail();
    Node* getHead();
    ~XorLinkedList();
private:
    //unsigned long doXor(unsigned long a, unsigned long b);
    int length;
    void setTail(Node* node_ptr);
    int findShortestDirection();
    Node* tail;
    Node* head;
};
