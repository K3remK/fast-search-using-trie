//
// Created by kk034505 on 4/17/2024.
//
/**
 * This class is useful to handle words related with opening file, reading from a file and writing to a file.
 */

#include "FileHandler.h"

string dictionarySize;
/**
 * The constructor of the FileHandler class.
 * @param inputFLocation - the location of the input file.
 * @param outputFLocation - the location of the output file.
 * @param dictionaryFileLocation - the location of the dictionary file.
 * @param trie - the trie to be used for storing dictionary.
 */
FileHandler::FileHandler(const string &inputFLocation, const string &outputFLocation, const string &dictionaryFileLocation, Trie* trie) {
    inputF.open(inputFLocation, ios::in);
    outputF.open(outputFLocation, ios::out);
    dictionaryF.open(dictionaryFileLocation, ios::in);
    this->trie = trie;
}
/**
 * This function is a helper function to be able split lines into separate words.
 * @param line - the line to be split into words.
 * @param delim - the character that the line will be split according to.
 * @param lineArray - the array to hold words in to line.
 */
void FileHandler::split(const string &line, const char &delim, string *lineArray) {
    int count = 0;
    string word;
    for(char currentLetter : line) {
        if(currentLetter == delim) {
            lineArray[count++] = word;
            word = "";
        } else {
            word += currentLetter;
        }
    }
    lineArray[count] = word;
}
/**
 * Fills the trie with the words in the dictionary file.
 */
void FileHandler::fillTrie() {
    //string dictionarySize;
    std::getline(dictionaryF, dictionarySize);
    for(int i = 0; i < stoi(dictionarySize); i++) {
        string word;
        getline(dictionaryF, word);
        trie->addWord(word);
    }
    dictionaryF.close();
}
/**
 * Reads the instructions from input file and applies either searching a word or finding prefixes. Prints out the result into output file.
 */
void FileHandler::applyInstructions() {
    string numberOfInstructions;
    getline(inputF, numberOfInstructions);
    for(int i = 0; i < stoi(numberOfInstructions); i++) {
        string line;
        getline(inputF, line);
        string lineArray[2];
        split(line, ' ', lineArray);
        if(lineArray[0] == "search") {
            outputF << (trie->searchWord(lineArray[1]) ? "true" : "false") << endl;
        } else if(lineArray[0] == "prefix") {
            int length = 0;
            string words[stoi(dictionarySize) + 1];
            trie->searchWordsWithPrefix(lineArray[1], words,length);
            for(int k = 0; k < length; k++) {
                if(k == length - 1) {
                    outputF << words[k];
                } else {
                    outputF << (words[k] + " ");
                }
            }
            outputF << endl;
        }
    }
    inputF.close();
    outputF.close();
}

