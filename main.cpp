//
//  main.cpp
//  XOR-Linked-List
//
//  Created by Jonathan Morales on 8/28/18.
//  Copyright © 2018 Jonathan Morales. All rights reserved.
//

#include <iostream>
#include "XorLinkedList.h"


/*8/31/2018
 to do:
    clean up push function
    add comments
*/

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    XorLinkedList* list = new XorLinkedList();
    list->push(1);
    list->push(2);
    list->push(3);
    list->push(4);
    list->push(5);
    
    list->traverse(0);
    list->add(9,0);
    list->traverse(1);
    list->traverse(1);
    list->traverse(0, 5);
    return 0;
} 
