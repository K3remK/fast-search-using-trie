//
// Created by kk034505 on 4/17/2024.
//
/**
 * This class represents the nodes of a trie structure.
 */

#include "TrieNode.h"

/**
 * Constructor of the TrieNode class. Inıtialize the endOfWord member variables which indicates whether current node is end of a word or not.
 * Initialize the children member variable which holds the children of this current node.
 * @param data - the data that this node will hold.
 */
TrieNode::TrieNode(char data) {
    this->data = data;
    this->endOfWord = false;
    children = new TrieNode*[ALPHABET_SIZE]{nullptr};
}
/**
 * Access the data that this node holds.
 * @return - returns the data member variable.
 */
char TrieNode::getData() {
    return this->data;
}
/**
 * Set whether this nodes represents end of a word or not.
 * @param value - the value to be set.
 */
void TrieNode::setEndOfWord(bool value) {
    this->endOfWord = value;
}
/**
 * Access the endOfWord member function.
 * @return - true if this node is end of a word, false otherwise.
 */
bool TrieNode::isEndOfWord() {
    return endOfWord;
}
/**
 * Access the children of this node.
 * @return - returns the children list member variable.
 */
TrieNode **TrieNode::getChildren() {
    return this->children;
}
/**
 * Access a specific child that holds the specified data.
 * @param d - the data that required child holds.
 * @return - returns the child node that holds specified data, nullptr if such child does not exist.
 */
TrieNode* TrieNode::getChild(char d) {
    return children[d - 'a'];
}
/**
 * Add a child to this node.
 * @param child - the child node to be added.
 */
void TrieNode::addChild(TrieNode *child) {
    children[child->getData() - 'a'] = child;
}

