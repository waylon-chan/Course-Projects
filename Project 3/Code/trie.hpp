#include <iostream>
#include <string>
#include "node.hpp"

using namespace std;


class Trie {
    public:
        Node* rootNode;
        int capacity;
        Trie();
        ~Trie();
        bool insert(string word);
        int outputPrefix(string prefix);
        bool erase(string word);
        Node* eraseFunction(Node* node, string word, int count);
        void printTrie();
        void printTrieFunction(Node* node, string word);
        void isEmpty();
        void clearTrie();
        int sizeOfTrie();
};