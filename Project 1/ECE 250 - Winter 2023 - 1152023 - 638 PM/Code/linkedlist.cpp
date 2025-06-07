#include "linkedlist.hpp"
#include <string>
#include <iostream>

using namespace std;

LinkedList::LinkedList(int n){
    //this just initializes the head to nullptr, 
    //the count of nodes u have to 0
    //and set the max number capcity to a passed in n
    head = nullptr;
    currentNumNodes = 0;
    maxLength = n;
} 

LinkedList::~LinkedList(){
    while(head != nullptr){ 
        Node *temp = head; 
        head = head->next; 
        delete temp;
    }
} 

bool LinkedList::def(string name, double val){
    //check if the name already exists in the array, if it does return false (iterate over)
    //if it doesnt, just make a new node, and add it to the fronnt of the linked list by setting that node to point to whatever head points to and head to that new one
    Node* current = head;
    while(current != nullptr){
        if(current->name == name){
            return false;
        }
        current = current->next;
    }
    if(currentNumNodes <= maxLength){
        currentNumNodes++;
        Node* newNode = new Node;
        newNode->name = name;
        newNode->val = val;
        newNode->next = head; 
        head = newNode; 
        return true;
    }
    return false;
}

bool LinkedList::add(string x, string y, string z){
    //loop over the array and check if all three variable names exist, return false if they dont
    //when ur looping over, you want to store the node at which you found the names x, y, and z,
    //that way, when ur done looping and they all exist, its really easy to just say ptrZ->value = ptrX->value + ptrY->value
    Node* current = head;
    Node* ptrX = nullptr; 
    Node* ptrY = nullptr; 
    Node* ptrZ = nullptr;
    while(current != nullptr){
        if(current->name == x){
            ptrX = current; 
        }
        if(current->name == y){
            ptrY = current;
        }
        if(current->name == z){
            ptrZ = current;
        }
        current = current->next;
    }
    if((ptrX == nullptr) || (ptrY == nullptr) || (ptrZ == nullptr)){
        return false;
    }
    ptrZ->val = ptrX->val + ptrY->val; 
    return true;
}   

bool LinkedList::sub(string x, string y, string z){
    //same thing as add just change the operation
    Node* current = head;
    Node* ptrX = nullptr; 
    Node* ptrY = nullptr; 
    Node* ptrZ = nullptr;
    while(current != nullptr){
        if(current->name == x){
            ptrX = current; 
        }
        if(current->name == y){
            ptrY = current;
        }
        if(current->name == z){
            ptrX = current;
        }
        current = current->next;
    }
    if((ptrX == nullptr) || (ptrY == nullptr) || (ptrZ == nullptr)){
        return false;
    }
    ptrZ->val = ptrX->val - ptrY->val;
    return true;
}

bool LinkedList::rem(string name){
    //check if the head is the one we want to remove first, if it is do that
    //otherwise, loop starting from head->next and keep a previous node, since we want to set the previous to the currents next when we remove current
    //remember to free memory with delete 

    //eg prev->current->next;
    //if we want to remove current since its name matches, then we need to set previous to the currents next
    if (currentNumNodes == 0) { 
        return false; 
    }
    Node* current = head;
    if(current->name == name){
        head = current->next;
        delete current;
        return true;
    }
    current = current->next;
    Node* previous = head;
    while(current != nullptr){
        if(current->name == name){
            previous->next = current->next;
            delete current;
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false;
}

void LinkedList::prt(string name){
    Node* current = head; 
    while(current != nullptr){
        if (current->name == name){
            cout << current->val << endl;
            return;
        }
        current = current->next; 
    }
    cout << "variable " << name << " not found" << endl;
}

void LinkedList::printLinkedList() { 
    Node* current = head; 
    while (current != nullptr) {
        cout << "Name: " << current->name << " value: " << current->val << endl;
        current = current->next;
    }
}


    