#include "priorityqueue.hpp"
#include <vector>

using namespace std;

PriorityQueue::PriorityQueue(){
    size = 0;
}

PriorityQueue::~PriorityQueue(){

}

bool PriorityQueue::isEmpty(){
    return size;
}

pair<int,int> PriorityQueue::findMin(){
    pair<int,int> initial = keyVertexPairs[0];
    pair<int,int> final = keyVertexPairs[size-1];
    keyVertexPairs[0] = final;
    queuePosition[initial.second] = size-1;
    queuePosition[final.second] = 0;
    size--;
    minHeapify(0);
    return initial;
}

void PriorityQueue::minHeapify(int index){
    int min, left, right;
    min = index;
    left = 1 + 2*index;
    right = 2 + 2*index;

    if(left < size && keyVertexPairs[left].second < keyVertexPairs[min].second){
        min = left;
    }
    if(right < size && keyVertexPairs[right].second < keyVertexPairs[min].second){
        min = right;
    }

    if(min != index){
        pair<int,int> minPair = keyVertexPairs[min];
        pair<int,int> indexPair = keyVertexPairs[index];

        keyVertexPairs[min].first = index;
        keyVertexPairs[index].first = min;
        minHeapify(min);
    }
}

void PriorityQueue::decreaseKey(int vertex, int key){
    int index = queuePosition[vertex];
    keyVertexPairs[index].first = key;
    while(index && keyVertexPairs[index].first < keyVertexPairs[(index-1)/2].first){

        // swap positions of vertices
        queuePosition[keyVertexPairs[index].second] = (index-1)/2;
        queuePosition[keyVertexPairs[(index-1)/2].second] = index;
        index = (index-1)/2;
    }
}