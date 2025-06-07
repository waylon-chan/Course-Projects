#include "process.hpp"
#include <vector>
#include <iostream>

using namespace std;

class OrderedHashtable{
    private:
        vector<Process>* orderedHashTable;
        int m;
        int pageSize;
        int* memory;
        bool* occupied;
        int currentSize;
    public:
        OrderedHashtable(int n, int p);
        ~OrderedHashtable();
        bool insert(unsigned int processID);
        int search(unsigned int processID);
        bool write(unsigned int processID, int address, int x);
        void read(unsigned int processID, int address);
        bool del(unsigned int processID);
        void print(int index);
};