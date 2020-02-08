//
//  Node.hpp
//  leetcodembp17
//
//  Created by ehson Assani on 1/12/20.
//  Copyright © 2020 ehson Assani. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <iostream>

using namespace std;
class Node{
public:
    Node();
    ~Node();
    Node(int x, string y);
    void setInitials(int x, string y);
    int getInitialOne();
    string getInitialTwo();
private:
    int x;
    string y;
    const int ALPHABETS = 26;
};
#endif /* Node_hpp */
