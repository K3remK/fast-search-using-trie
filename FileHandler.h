//
// Created by kk034505 on 4/17/2024.
//

#ifndef FAST_SEARCH_USING_TRIES_KEREMKARAMANLIOGLU_FILEHANDLER_H
#define FAST_SEARCH_USING_TRIES_KEREMKARAMANLIOGLU_FILEHANDLER_H

#include <fstream>
#include <string>
#include "Trie.h"

using namespace std;

class FileHandler{
private:
    fstream inputF, outputF,dictionaryF;
    Trie* trie;
    static void split(const string &line, const char &delim, string* lineArray);
public:
    FileHandler(const string &inputFLocation, const string &outputFLocation, const string &dictionaryFileLocation, Trie* trie);
    void fillTrie();
    void applyInstructions();
};

#endif //FAST_SEARCH_USING_TRIES_KEREMKARAMANLIOGLU_FILEHANDLER_H
