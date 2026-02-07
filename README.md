# 🌲 Fast Search Using Trees

## 🚀 Project Overview

This project implements a high-performance search system using a Trie (Prefix Tree) data structure. It is designed to efficiently handle dictionary operations such as **checking if a word exists** and **finding all words that start with a given prefix**.

The core functionality is encapsulated in C++ and uses a file handling system to process input commands (`search` and `prefix`) against a loaded dictionary file.

## ❓ Why Use a Trie?

### 🐢 The Problem with Arrays
In a traditional approach using an unsorted array or a linked list, searching for a word requires iterating through the collection and comparing the target word with every entry.

-   **Time Complexity (Search)**: $O(N \cdot L)$, where $N$ is the number of words in the dictionary and $L$ is the average length of a word.
-   **Time Complexity (Prefix Search)**: Similarly $O(N \cdot L)$, as you must check every single word to see if it starts with the prefix.

As the dictionary grows (large $N$), performance degrades linearly.

### ⚡ The Trie Advantage
A Trie organizes words by their characters, creating a tree where each path represents a word or a prefix.

-   **Time Complexity (Search)**: $O(L)$, where $L$ is the length of the word being searched.
    -   🌟 *Crucial Note*: The speed is **independent** of the dictionary size ($N$). Checking a 5-letter word takes roughly the same time whether the dictionary has 100 words or 1,000,000 words.
-   **Time Complexity (Prefix Search)**: $O(P + K)$, where $P$ is the length of the prefix and $K$ is the number of characters in the matching words (to retrieve them).
    -   This is significantly faster for autocomplete features, as it avoids scanning unrelated words entirely.

### 📊 Performance Comparison

| Operation | Array / List | Trie (This Project) |
| :--- | :--- | :--- |
| **Search Word** | $O(N \cdot L)$ | $O(L)$ |
| **Prefix Search** | $O(N \cdot L)$ | $O(P + K)$ |
| **Space Complexity** | $O(N \cdot L)$ | $O(Total Characters)$ * |

*\* Tries can use more memory than arrays due to node pointers, but they effectively compress shared prefixes.*

## 🛠️ Build System

This project uses **CMake** as its build system, ensuring cross-platform compatibility and easy build management.

### ✅ Requirements
-   C++17 compiler (GCC, Clang, MSVC)
-   CMake 3.10 or higher

## 🏃‍♂️ How to Build and Run

### 1️⃣ Build the Project
I recommend an "out-of-source" build to keep your directory clean.

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### 2️⃣ Prepare Input Files
Ensure you have the following files in your project directory (or provide paths to them):
-   📄 `dictionary.txt`: The list of valid words.
-   📄 `input.txt`: The commands to execute (e.g., `search word`, `prefix pre`).

### 3️⃣ Run the Executable
The program requires 3 arguments:
1.  Path to the input file.
2.  Path to the dictionary file.
3.  Path to the output directory (where `out.txt` will be created).

**Example (running from the `build` directory):**

```bash
# Windows
.\fast-search-using-trees.exe ..\input.txt ..\dictionary.txt .

# Linux / Mac
./fast-search-using-trees ../input.txt ../dictionary.txt .
```

This will generate an `out.txt` file in the current directory containing the results of your search and prefix queries.
