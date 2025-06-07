#include "openHashtable.hpp"
#include <iostream>

using namespace std;

OpenHashtable::OpenHashtable(int n, int p){
    pageSize = p;
    m = n/p;
    currentSize = 0;
    memory = new int[n];
    openHashTable = new Process[n/p];
}
OpenHashtable::~OpenHashtable(){
    for(int i = 0; i < m; i++){
        openHashTable[i].~Process();
    }
}
bool OpenHashtable::insert(unsigned int processID){
    if(search(processID) != -1){
        return false;
    }
    int hashValue = 0;
    for(int i = 0; i < m; i++){
        if(currentSize < m){
            Process* newProcess = new Process(processID, i*pageSize);
            (processID/m)%2 == 1 ? hashValue = (processID/m)%m + 1 : hashValue = (processID/m)%m;
            openHashTable[((processID%m) + i) * hashValue].setProcessID(processID);
        }
    }
}
int OpenHashtable::search(unsigned int processID){
    int hashValue = ((processID/m)%m) % 2 == 0 ?  (processID/m)%m + 1 : (processID/m)%m;
    int index = processID % m; 
    int original = index; 
    //first thing you want to check is if the primary hash contains the correct PID, 
    //If it doesnt then you want to continuously add the offset and check that index until you've made one complete cycle
    if (openHashTable[index].getProcessID() == processID){ 
        return index; 
    }
    index = (index + hashValue)%m; 
    while (index != original){ 
        if (openHashTable[index].getProcessID() == processID) { 
            return index; 
        }
        index = (index+hashValue)%m; 
    }
    return -1;
}

bool OpenHashtable::write(unsigned int processID, int address, int x){
    if(address > pageSize || address < 0 || search(processID) == -1){
        return false;
    }
    int hashValue = ((processID/m)%m) % 2 == 0 ?  (processID/m)%m + 1 : (processID/m)%m;
    if(openHashTable[((processID%m) + address) * hashValue].getProcessID() == processID){
        memory[((processID%m) + address) * hashValue] = x;
        return true;
    }
    return false;
}
void OpenHashtable::read(unsigned int processID, int address){
    if(address > pageSize || address < 0 || search(processID) == -1){
        cout << "failure" << endl;
        return;
    }
    int hashValue = ((processID/m)%m) % 2 == 0 ?  (processID/m)%m + 1 : (processID/m)%m;
    if(openHashTable[((processID%m) + address) * hashValue].getProcessID() == processID){
        cout << memory[((processID%m) + address) * hashValue] << endl;
        return;
    }
}
bool OpenHashtable::del(unsigned int processID){
    if(search(processID)){
        openHashTable[search(processID)].setProcessID(0);
        return true;
    }else if(search(processID) == -1){
        return false;
    }
}


