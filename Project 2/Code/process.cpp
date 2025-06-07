#include <iostream>
#include "process.hpp"

using namespace std;

Process::Process(unsigned int id, int index){
    processID = id;
    startIndex = index;
}

Process::~Process(){
    
}

void Process::setProcessID(unsigned int id){
    processID = id;
}

void Process::setStartIndex(int index){
    startIndex = index;
}

unsigned int Process::getProcessID(){
    return processID;
}

int Process::getStartIndex(){
    return startIndex;
}

