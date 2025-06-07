#include <iostream>
#include "orderedHashtable.hpp"
#include "openHashtable.hpp"
#include <vector>


using namespace std;

int main() { 
    OrderedHashtable* orderedHashtable= nullptr;
    OpenHashtable* openHashtable = nullptr;
	string cmd;
    cin >> cmd;
    if(cmd == "ORDERED"){
        while(cin >> cmd){
            if(cmd == "M"){
                int n;
                int p;
                cin >> n >> p;
                orderedHashtable = new OrderedHashtable(n,p);
                cout << "success" << endl;
            }else if(cmd == "INSERT"){
                unsigned int processID;  
                cin >> processID;
                if(orderedHashtable->insert(processID)){
                    cout << "success" << endl;
                }else{
                    cout << "failure" << endl;
                }
            }else if(cmd == "SEARCH"){
                unsigned int processID;
                cin >> processID;
                if(orderedHashtable->search(processID) != -1){
                    cout << "found " << processID << " in " << orderedHashtable->search(processID) << endl;
                }else{
                    cout << "not found" << endl;
                }
            }else if(cmd == "WRITE"){
                unsigned int processID;
                int address;
                int x;
                cin >> processID >> address >> x;
                if(orderedHashtable->write(processID, address, x)){
                    cout << "success" << endl;
                }else{
                    cout << "failure" << endl;
                }
            }else if(cmd == "READ"){
                unsigned int processID;
                int address;
                cin >> processID >> address;
                orderedHashtable->read(processID, address);
            }else if(cmd == "PRINT"){
                int m;
                cin >> m;
                orderedHashtable->print(m);
            }else{
                break;
            }
        }
        delete orderedHashtable;
    }else{
        while(cin >> cmd){
            if(cmd == "M"){
                int n;
                int p;
                cin >> n >> p;
                openHashtable = new OpenHashtable(n,p);
                cout << "success" << endl;
            }else if(cmd == "INSERT"){
                unsigned int processID;  
                cin >> processID;
                if(openHashtable->insert(processID)){
                    cout << "success" << endl;
                }else{
                    cout << "failure" << endl;
                }
            }else if(cmd == "SEARCH"){
                unsigned int processID;
                cin >> processID;
                if(openHashtable->search(processID) != -1){
                    cout << "found " << processID << " in " << openHashtable->search(processID) << endl;
                }else{
                    cout << "not found" << endl;
                }
            }else if(cmd == "WRITE"){
                unsigned int processID;
                int address;
                int x;
                cin >> processID >> address >> x;
                if(openHashtable->write(processID, address, x)){
                    cout << "success" << endl;
                }else{
                    cout << "failure" << endl;
                }
            }else if(cmd == "READ"){
                unsigned int processID;
                int address;
                cin >> processID >> address;
                openHashtable->read(processID, address);
            }else if(cmd == "PRINT"){
                int m;
                cin >> m;
                openHashtable->print(m);
            }else{
                break;
            }
        }
        delete openHashtable;
    }
	return 0;
}