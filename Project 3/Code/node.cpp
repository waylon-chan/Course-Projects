#include <iostream>
#include "node.hpp"
using namespace std;

Node::Node(){
    for(int i=0; i<26; i++){
        children[i] = nullptr;
    }
    endWord = false;
}

void Node::setChild(Node* child, int index){
    children[index] = child;
}

Node* Node::getChild(int index){
    return children[index];
}

bool Node::hasChild(){
    for(int i = 0; i < 26; i++){
        if(children[i] != nullptr){
            return true;
        }
    }
    return false;
}

void Node::setEndWord(bool isEndWord){
    endWord = isEndWord;
}

bool Node::getEndWord(){
    return endWord;
}