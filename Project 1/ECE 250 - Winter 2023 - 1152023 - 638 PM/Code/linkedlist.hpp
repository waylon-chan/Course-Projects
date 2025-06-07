#ifndef linkedList
#define linkedList

#include "node.hpp"
#include <string> 

using namespace std;

class LinkedList {
    //Declare Private Variables
    private:
        int maxLength;
        int currentNumNodes;
        Node* head;
    
    //Declare Public Variables
    public:
        LinkedList(int capacity);
        ~LinkedList();
        bool def(string name, double val);
        bool add(string x, string y, string z);
        bool sub(string x, string y, string z);
        bool rem(string name);
        void prt(string name);
        void printLinkedList();
};

#endif