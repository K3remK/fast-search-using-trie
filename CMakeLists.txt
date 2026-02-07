cmake_minimum_required(VERSION 3.10)
project(fast-search-using-trees)

set(CMAKE_CXX_STANDARD 17)

add_executable(fast-search-using-trees
    Main.cpp
    FileHandler.cpp
    Trie.cpp
    TrieNode.cpp
)
