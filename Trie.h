//
// Created by kk034505 on 4/17/2024.
//

#ifndef FAST_SEARCH_USING_TRIES_KEREMKARAMANLIOGLU_TRIE_H
#define FAST_SEARCH_USING_TRIES_KEREMKARAMANLIOGLU_TRIE_H

#include "TrieNode.h"
#include <iostream>

using namespace std;

class Trie{
private:
    TrieNode* root;
    void searchWordsWithPrefixHelper(TrieNode* current, const string& prefix, string* words, int &length);
public:
    Trie();
    void addWord(const string& word);
    bool searchWord(const string& word);
    void searchWordsWithPrefix(const string &prefix, string* words,int &length);
};

#endif //FAST_SEARCH_USING_TRIES_KEREMKARAMANLIOGLU_TRIE_H
