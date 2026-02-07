#include <iostream>
#include "FileHandler.h"
using namespace std;
int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Usage: " << argv[0] << " <input file> <dictionary file> <output file>" << endl;
        return 1;
    }
    string inputFileLocation = argv[1];
    string dictionaryFileLocation = argv[2];
    string outputFileLocation = string(argv[3]) + "\\out.txt";
    Trie* trie = new Trie();
    FileHandler fileHandler(inputFileLocation, outputFileLocation, dictionaryFileLocation, trie);
    fileHandler.fillTrie();
    fileHandler.applyInstructions();
    return 0;
}
