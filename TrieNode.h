//
// Created by kk034505 on 4/17/2024.
//

#ifndef FAST_SEARCH_USING_TRIES_KEREMKARAMANLIOGLU_TRIENODE_H
#define FAST_SEARCH_USING_TRIES_KEREMKARAMANLIOGLU_TRIENODE_H

const int ALPHABET_SIZE = 26;

class TrieNode{
private:
    char data;
    TrieNode** children;
    bool endOfWord;
public:
    TrieNode(char data);
    char getData();
    void setEndOfWord(bool value);
    bool isEndOfWord();
    TrieNode** getChildren();
    TrieNode* getChild(char d);
    void addChild(TrieNode* child);
};

#endif //FAST_SEARCH_USING_TRIES_KEREMKARAMANLIOGLU_TRIENODE_H
