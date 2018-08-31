//
//  Node.h
//  XOR-Linked-List
//
//  Created by Jonathan Morales on 8/28/18.
//  Copyright © 2018 Jonathan Morales. All rights reserved.
//

#ifndef Node_h
#define Node_h


#endif /* Node_h */
class Node {
public:
    Node(int value, unsigned long address);
    void setData(int value);
    void setNpx(unsigned long n);
    int getData();
    unsigned long getNpx();
    ~Node();
private:
    unsigned long npx;
    int data;
};
