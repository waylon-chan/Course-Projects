// #ifndef PriorityQueue
// #define PriorityQueue

#include <vector>

using namespace std;

class PriorityQueue{
    public:
        int queuePosition[500001];
        pair<int,int> keyVertexPairs[500001];
        int size;
        PriorityQueue();
        ~PriorityQueue();
        bool isEmpty();
        pair<int,int> findMin();
        void minHeapify(int index);
        void decreaseKey(int vertex, int key);
};

//#endif