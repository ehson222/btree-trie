//
//  Trie.cpp
//  leetcodembp17
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
        cout << temp->count << " words starting with " << word << endl;
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
