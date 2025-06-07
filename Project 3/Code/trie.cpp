#include <iostream>
#include <string>
#include "node.hpp"
#include "trie.hpp"
using namespace std;

Trie::Trie(){
    rootNode = nullptr;
    capacity = 0;
}

Trie::~Trie(){
    
}

bool Trie::insert(string word){
    Node* current = rootNode; 
    for(int i = 0; i < word.length(); i++){
        if((word[i]-'A') < 65 || (word[i]-'A') > 90){
            //throw illegal exception
            return false;
        }
        if(current->children[word[i]-'A'] == nullptr){
            Node* x = new Node();
            current->children[word[i]-'A'] = x;
        }
        current = current->children[word[i]-'A'];
    }
    if(current->endWord == true){
        return false;
    }else{
        current->endWord = true;
        capacity++;
        return true;
    }
}

int Trie::outputPrefix(string prefix){
     
}

bool Trie::erase(string word){
    return eraseFunction(rootNode, word, 0);
}

Node* Trie::eraseFunction(Node* x, string word, int count){

    if(!x){
        return nullptr;
    }

    if(count == word.length()){
        if(x->endWord){
            x->endWord = false;
        }
        if(x->hasChild()){
            delete (x);
            x = NULL;
        }
        return x;
    }

    if(x->children[word[count]-'A']){
        x->children[word[count]-'A'] = eraseFunction(x->children[word[count]-'A'], word, count + 1);
    }else{
        return nullptr;
    }

    if(!x->hasChild() && !x->endWord){
        delete (x);
        x = NULL;
    }
    return x;
}

void Trie::printTrie(){
    if(rootNode == nullptr){
        return;
    }
    for(int i = 0; i < 26; i++){
        if(rootNode->children[i]){
            string word = to_string('A' + i);
            printTrieFunction(rootNode->children[i], word);
        }
    }
}

void Trie::printTrieFunction(Node* x, string word){
    if(x->endWord){
        cout << word << ' ';
    }
    for(int i = 0; i < 26; i++){
        word += i + 'A';
        if(x->children[i]){
            printTrieFunction(x->children[i], word);
        }
    }
}

void Trie::isEmpty(){
    if(capacity){
        cout << "empty 0" << endl;
    }else{
        cout << "empty 1" << endl;
    }
}

void Trie::clearTrie(){
    
}

int Trie::sizeOfTrie(){
    return capacity;
}