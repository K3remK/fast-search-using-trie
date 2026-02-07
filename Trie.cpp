//
// Created by kk034505 on 4/17/2024.
//
/**
 * This class implements the trie data structure to be able to apply fast searches with words.
 */

#include "Trie.h"
#include <iostream>

using namespace std;

/**
 * The constructor of the Trie class. Initializes member variable root of the trie. Root is the beginning of the trie structure.
 */
Trie::Trie() {
    root = new TrieNode('0');
}
/**
 * This functions is a recursive helper function to searchWordsWithPrefix. It traverses the trie and finds specific words that start with specified prefix.
 * @param current - the current node that is to be checked.
 * @param prefix - the prefix that the searched words should start with.
 * @param words - the list of required words.
 * @param length - the length of words list.
 */
void Trie::searchWordsWithPrefixHelper(TrieNode *current, const string &prefix, string *words, int &length) {
    if(current->isEndOfWord()){
        words[length++] = prefix;
    }
    TrieNode** children = current->getChildren();
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        TrieNode* currentChild = children[i];
        if(currentChild) {
            searchWordsWithPrefixHelper(currentChild, prefix + currentChild->getData(), words, length);
        }
    }
}
/**
 * Adds a new word to the trie.
 * @param word - the word to be added.
 */
void Trie::addWord(const string& word) {
    TrieNode* tmpRoot = root;
    for(char currentLetter : word) {
        if(!(tmpRoot->getChild(currentLetter))) {
            tmpRoot->addChild(new TrieNode(currentLetter));
        }
        tmpRoot = tmpRoot->getChild(currentLetter);
    }
    tmpRoot->setEndOfWord(true);
}
/**
 * Searches the specified word throughout the trie.
 * @param word - the word that is to be searched.
 * @return - return true if such word exist in the trie, false otherwise.
 */
bool Trie::searchWord(const string& word) {
    TrieNode* tmpRoot = root;
    for(char currentLetter : word) {
        if(!tmpRoot->getChild(currentLetter)) {
            return false;
        }
        tmpRoot = tmpRoot->getChild(currentLetter);
    }
    return tmpRoot->isEndOfWord();
}
/**
 * Searches such words throughout the trie that starts with specified prefix. Uses searchWordsWithPrefixHelper function.
 * @param prefix - the prefix that the searched words should start with.
 * @param words - the required words list.
 * @param length - the length of word list.
 */
void Trie::searchWordsWithPrefix(const string &prefix, string* words, int &length) {
    TrieNode* current = root;
    for(char currentLetter : prefix) {
        if(!(current->getChild(currentLetter))) {
            return;
        }
        current = current->getChild(currentLetter);
    }
    searchWordsWithPrefixHelper(current, prefix, words, length);
}

