//
//  Node.cpp
//  XOR-Linked-List
//
//  Created by Jonathan Morales on 8/28/18.
//  Copyright © 2018 Jonathan Morales. All rights reserved.
//

#include <stdio.h>
#include "Node.h"

Node::Node(int value, unsigned  long address) {
    data = value;
    npx = address;
}

void Node::setNpx(unsigned long n) {
    npx = n;
}

void Node::setData(int value) {
    data = value;
}

int Node::getData() {
    return data;
}

unsigned long Node::getNpx() {
    return npx;
}

Node::~Node(){

}
