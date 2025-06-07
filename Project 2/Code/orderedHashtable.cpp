#include "orderedHashtable.hpp"
#include <vector>

using namespace std;

OrderedHashtable::OrderedHashtable(int n, int p){
    pageSize = p;
    m = n/p;
    memory = new int[n];
    occupied = new bool[m]{false};
    orderedHashTable = new vector<Process>[n/p];
    currentSize = 0;
}

OrderedHashtable::~OrderedHashtable(){
    for(int i = 0; i < m; i++){
        orderedHashTable[i].erase(orderedHashTable[i].begin(), orderedHashTable[i].end());
    }
}

bool OrderedHashtable::insert(unsigned int processID){
    if(search(processID) != -1 || currentSize + 1 > m){
        return false;
    }

    for(int i = 0; i < m; i++){
        if(occupied[i] == false){
            occupied[i] = true;
            Process newProcess(processID, i*pageSize);
            if(orderedHashTable[processID%m].size() == 0){
                currentSize++;
                orderedHashTable[processID%m].insert(orderedHashTable[processID%m].begin() + i, newProcess);
                return true;
            }
            for (int j=0; j<orderedHashTable[processID%m].size(); j++) {
                if (processID > orderedHashTable[processID%m][j].getProcessID()) {
                    currentSize++;
                    orderedHashTable[processID%m].insert(orderedHashTable[processID%m].begin() + i, newProcess);
                    return true;
                }
            }
        }
    }
    return false;
}

int OrderedHashtable::search(unsigned int processID){
    for(int i = 0; i< orderedHashTable[processID%m].size(); i++){
        if(processID == orderedHashTable[processID%m][i].getProcessID()){
            return processID%m;
        }
    }
    return -1;
}
bool OrderedHashtable::write(unsigned int processID, int address, int x){
    if(address > pageSize || address < 0 || search(processID) == -1){
        return false;
    }
    for(int j = 0; j < orderedHashTable[processID%m].size(); j++){
        if(orderedHashTable[processID%m][j].getProcessID() == processID){
            memory[orderedHashTable[processID%m][j].getStartIndex() + address] = x;
            return true;
        }
    }
    return false;
}

void OrderedHashtable::read(unsigned int processID, int address){
    if(address > pageSize || address < 0){
        cout << "failure" << endl;
        return;
    }
    for(int j = 0; j < orderedHashTable[processID%m].size(); j++){
        if(orderedHashTable[processID%m][j].getProcessID() == processID){
            cout << memory[orderedHashTable[processID%m][j].getStartIndex() + address] << endl;
            return;
        }
    }
    cout << "failure" << endl;
}


bool OrderedHashtable::del(unsigned int processID){
    for(int i = 0; i < m; i++){
        if(occupied[i] == true){
            for(int j = 0; j< orderedHashTable[i].size(); j++){
                if(processID == orderedHashTable[i][j].getProcessID()){
                    currentSize--;
                    orderedHashTable[i].erase(orderedHashTable[i].begin() + j);
                    return true;
                }
            }
        }
    }
    return false;
}

void OrderedHashtable::print(int index){
    if(index > pageSize || orderedHashTable[index].empty()){
        cout << "chain is empty" << endl;
        return;
    }
    for(int i = 0; i < orderedHashTable[index].size(); i++){
        cout << orderedHashTable[index][i].getProcessID() << endl;
        return;
    }

}