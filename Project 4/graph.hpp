#include <vector>
#include <tuple>
#include "illegal_exception.hpp"
#include "priorityqueue.hpp"

using namespace std;

class Graph{
    public:
        vector<tuple<int, int>> adjacencyList[50001]; // vertex + corresponding adj. list
        int mstCost;
        Graph();
        ~Graph();
        bool illegalVertexArgument(int vertex);
        bool illegalWeightArgument(int weight);
        bool insert(int a, int b, int w);
        void print(int a);
        bool del(int a);
        void findMST();
        int cost();
        friend class PriorityQueue;
};