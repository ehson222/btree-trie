//
//  Trie.hpp
//
//  Created by ehson Assani on 2/3/20.
//  Copyright © 2020 ehson Assani. All rights reserved.
//

#ifndef Trie_hpp
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



#endif /* Trie_hpp */
