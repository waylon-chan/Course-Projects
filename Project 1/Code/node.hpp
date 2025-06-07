#pragma once
#include <string>

class Node {
    public:
        double val;
        std::string name;
        Node* next;
    
    // public:
    //     Node(double val, std::string name);
    //     ~Node();
    //     void setVal(double val);
    //     void setName(std::string val);
    //     void setNext(Node* node);
    //     double getVal();
    //     std::string getName();
    //     Node* getNext();
};