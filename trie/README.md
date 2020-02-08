# trie

```
//
//  Node.hpp
//
//  Created by ehson Assani on 1/12/20.
//  Copyright © 2020 ehson Assani. All rights reserved.
//

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

//
//  Node.cpp
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

//
//  Trie.hpp
//
//  Created by ehson Assani on 2/3/20.
//  Copyright © 2020 ehson Assani. All rights reserved.
//

#define Trie_hpp

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
/*
    For faster code readibility, user will receive bad access modifier due to improper encapsulation.
    Extra space is taken by TrieNodes for better debugging
 */
struct TrieNode{
    vector<TrieNode*> next;
    bool is_word;
    string the_word;
    char the_letter;
    int count;
    
    TrieNode() : next(26, nullptr), is_word(false), the_word(""), the_letter('\0'), count(0) {}
};

class Trie{
public:
    Trie();
    ~Trie();
    void insert(string& word);
    bool search(string& word);
    bool startsWith(string& word);
    
private:
    TrieNode* root;
    TrieNode* find_string(TrieNode* leaf, string& word);
    void clear(TrieNode* leaf);
};

//
//  Trie.cpp
//
//  Created by ehson Assani on 2/3/20.
//  Copyright © 2020 ehson Assani. All rights reserved.
//

#include "Trie.hpp"
#include<string>
#include<iostream>
#include<vector>


//struct TrieNode{
//    vector<TrieNode*> next;
//    bool is_word;
//    string the_word;
//    char the_letter;
//
//    TrieNode() : next(26, nullptr), is_word(false), the_word(nullptr), the_letter('\0') {}
//};

Trie::Trie() : root(new TrieNode) {}

Trie::~Trie(){
    clear(root);
}

void Trie::insert(string& word){
    TrieNode* temp = root;
    string curr_word = "";
    
    for(int i = 0; i < word.size(); ++i){
        if(temp->next[word[i] - 'a'] == nullptr){
            temp->next[word[i] - 'a'] = new TrieNode;
        }
        temp = temp->next[word[i] - 'a'];
        temp->count += 1;
        temp->the_letter = word[i];
        temp->the_word = (curr_word+=word[i]);
    }
    
    temp->is_word = true;
}

bool Trie::search(string& word){
    auto temp = find_string(root, word);
    
    if(temp && temp->is_word){
        return true;
    } else{
        return false;
    }
}

bool Trie::startsWith(string& word){
    auto temp = find_string(root, word);
    
    if(temp){
        cout << temp->count << " words starting with: " << word << endl;
        return true;
    } else{
        return false;
    }
}


TrieNode* Trie::find_string(TrieNode* leaf, string& word){
    auto temp = leaf;
    
    for(int i = 0; temp && i < word.size(); ++i){
        if(temp->next[word[i] - 'a']){
            temp = temp->next[word[i] -'a'];
        } else{
            temp = nullptr;
        }
    }
    
    return temp;
}

void Trie::clear(TrieNode* leaf){
    for(int i = 0; i < 26; ++i){
        if(leaf->next[i]){
            //std::cout << "deleting : " << leaf->next[i]->the_letter << std::endl;
            clear(leaf->next[i]);
        }
    }
    
    delete leaf;
}


int main(int argc, const char * argv[]) {

    Trie* tries;
    tries = new Trie();
    string ab = "stay", bc = "stone", cd = "story", de = "and", ef = "strong" , fg = "st";
    tries->insert(ab);
    tries->insert(bc);
    tries->insert(cd);
    tries->insert(de);
    if(tries->search(cd)){
        cout << "found " << cd << endl;
    } else{
        cout << cd << " does not exist\n";
    }
    tries->startsWith(fg);
    tries->~Trie();
};

output:
found story
3 words starting with: st
```
