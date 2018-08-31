//
//  main.cpp
//  XOR-Linked-List
//
//  Created by Jonathan Morales on 8/28/18.
//  Copyright © 2018 Jonathan Morales. All rights reserved.
//

#include <iostream>
#include "XorLinkedList.h"


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    XorLinkedList* list = new XorLinkedList();
    list->add(1);
    list->add(2);
    list->add(3);
    list->add(4);
    list->add(5);
    
    std::cout << list->remove(0) << std::endl;
    list->traverse(0);
    //list->traverse(1);
    //list->traverse(0, 5);
    return 0;
} 
