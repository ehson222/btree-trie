//
//  Node.cpp
//  leetcodembp17
//
//  Created by ehson Assani on 1/12/20.
//  Copyright © 2020 ehson Assani. All rights reserved.
//

#include "Node.hpp"
#include <iostream>
using namespace std;

Node::Node(){
    cout << " I AM A NODE\n";
}

Node::~Node(){
    cout << " I AM NODE DELETOR\n";
}

Node::Node(int x, string y){
    this->x = x;
    this->y = y;
    cout << " 2nd Constructor\n";
}

void Node::setInitials(int x, string y){
    this->x = x;
    this->y = y;
}

int Node::getInitialOne(){
    return x;
}

string Node::getInitialTwo(){
    return y;
}
