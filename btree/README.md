# btree
```
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

//
//  btree.cpp
//
//  Created by ehson Assani on 2/1/20.
//  Copyright © 2020 ehson Assani. All rights reserved.
//

#include "btree.hpp"
#include <stack>
#include <queue>
#include <iostream>

using namespace std;
btree::btree() : root(nullptr) {}

btree::~btree(){
    if(root){
        destroy_tree();
    }
}

void btree::destroy_tree(){
    destroy_tree(root);
}

void btree::destroy_tree(treenode* leaf){
    if(leaf){
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void btree::insert(int data){
    if(root){
        insert(root, data);
    } else{
        root = new treenode;
        root->val = data;
        root->left = nullptr;
        root->right = nullptr;
    }
}

void btree::insert(treenode *leaf, int data){
        if(leaf->val < data){
            if(leaf->right){
                insert(leaf->right, data);
            } else{
                leaf->right = new treenode;
                leaf->right->val = data;
                leaf->right->left = nullptr;
                leaf->right->right = nullptr;
            }
        } else if(leaf->val >= data){
            if(leaf->left){
                insert(leaf->left, data);
            } else{
                leaf->left = new treenode;
                leaf->left->val = data;
                leaf->left->left = nullptr;
                leaf->left->right = nullptr;
            }
        }
}

treenode* btree::search(int data){
    return (root) ? search(root, data) : nullptr;
}

treenode* btree::search(treenode* leaf, int data){
    if(leaf){
        if(leaf->val == data){
          return leaf;
        } else if(leaf->val < data){
            search(leaf->right, data);
        } else{
            search(leaf->left, data);
        }
    }
    return nullptr;
}

void btree::preOrder(){
    if(root){
        preOrder(root);
    }
}

void btree::preOrder(treenode* leaf){
    stack<treenode*> ts;
    ts.push(leaf);
    cout << "printing preOrder:\n";
    while(!ts.empty()){
        treenode* trav = ts.top();
        ts.pop();
        cout << trav->val << " ";
        if(trav->right){
            ts.push(trav->right);
        }
        if(trav->left){
            ts.push(trav->left);
        }
    }
    cout << endl;
}

void btree::inOrder(){
    if(root){
        inOrder(root);
    }
}

void btree::inOrder(treenode* leaf){
    stack<treenode*> ts;
    treenode* trav = leaf;
    cout << "printing inOrder:\n";
    while(trav || !ts.empty()){
        while(trav){
            ts.push(trav);
            trav = trav->left;
        }
        trav = ts.top();
        ts.pop();
        cout << trav->val << " ";
        trav = trav->right;
    }
    cout << endl;
}

void btree::postOrder(){
    if(root){
        postOrder(root);
    }
}

void btree::postOrder(treenode* leaf){
    stack<treenode*> ts;
    stack<treenode*> revts;
    
    ts.push(leaf);
    while(!ts.empty()){
        treenode* trav = ts.top();
        ts.pop();
        revts.push(trav);
        if(trav->left){
            ts.push(trav->left);
        }
        if(trav->right){
            ts.push(trav->right);
        }
    }
    cout << "printing postOrder\n";
    while(!revts.empty()){
        treenode* trav = revts.top();
        revts.pop();
        cout << trav->val << " ";
    }
    cout << endl;
}

void btree::levelOrder(){
    if(root){
        levelOrder(root);
    }
    cout << endl;
}

void btree::levelOrder(treenode* leaf){
    queue<treenode*> tq;
    tq.push(leaf);
    tq.push(nullptr);
    cout << "printing levelOrder(BFS)\n";
    while(!tq.empty()){
        treenode* trav = tq.front();
        tq.pop();
        if(trav){
            cout << trav->val << " ";
            if(trav->left){
                tq.push(trav->left);
            }
            if(trav->right){
                tq.push(trav->right);
            }
        } else{
            if(!tq.empty()){
                tq.push(nullptr);
            }
        }
    }
}

int btree::height(){
    try {
        if(root){
            cout << "printing tree height\n";
            return height(root) - 1;
        }
    } catch (exception) {
        cout << "empty tree\n";
    }
    return 0;
}

int btree::height(treenode* leaf){
    int left = 0, right = 0;
    if(leaf){
        left = height(leaf->left);
        right = height(leaf->right);
        return (max(left, right) + 1);
    }
    return 0;
}

int main(int argc, const char * argv[]) {

    btree* tree = new btree();
    tree->insert(5);
    tree->insert(8);
    tree->insert(3);
    tree->insert(2);
    tree->insert(1);
    tree->insert(7);
    tree->insert(10);
    tree->preOrder();
    tree->inOrder();
    tree->postOrder();
    tree->levelOrder();
    cout << tree->height();
    return 0;
};

output:
printing preOrder:
5 3 2 1 8 7 10 
printing inOrder:
1 2 3 5 7 8 10 
printing postOrder
1 2 3 7 10 8 5 
printing levelOrder(BFS)
5 3 8 2 7 10 1 
printing tree height
3

```
