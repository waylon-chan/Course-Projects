#include "process.hpp"
#include <vector>

using namespace std;

class OpenHashtable{
    private:
        Process* openHashTable;
        int currentSize;
        int m;
        int pageSize;
        int* memory;
    public:
        OpenHashtable(int n, int p);
        ~OpenHashtable();
        bool insert(unsigned int processID);
        int search(unsigned int processID);
        bool write(unsigned int processID, int address, int x);
        void read(unsigned int processID, int address);
        bool del(unsigned int processID);
        void print(int index);
};