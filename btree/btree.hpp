//
//  btree.hpp
//
//  Created by ehson Assani on 2/1/20.
//  Copyright © 2020 ehson Assani. All rights reserved.
//

#ifndef btree_hpp
#define btree_hpp

#include <stdio.h>
struct treenode{
    int val;
    treenode *left;
    treenode *right;
};

class btree{
public:
    btree();
    ~btree();
    void destroy_tree();
    void insert(int data);
    treenode* search(int data);
    void preOrder();
    void inOrder();
    void postOrder();
    void levelOrder();
    int height();
private:
    treenode *root;
    void destroy_tree(treenode *leaf);
    void insert(treenode *leaf, int data);
    treenode* search(treenode* leaf, int data);
    void preOrder(treenode* leaf);
    void inOrder(treenode* leaf);
    void postOrder(treenode* leaf);
    void levelOrder(treenode* leaf);
    int height(treenode* leaf);
};
#endif /* btree_hpp */
