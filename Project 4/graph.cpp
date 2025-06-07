#include <iostream>
#include <tuple>
#include <vector>
#include "illegal_exception.hpp"
#include "graph.hpp"
#include "priorityqueue.hpp"

using namespace std;

Graph::Graph(){
    mstCost = 0;
}

Graph::~Graph(){
    
}

bool Graph::illegalVertexArgument(int vertex){
    try{
        if(vertex > 50000 || vertex <= 0){
            throw illegal_exception();
        }
    }catch(illegal_exception){
            cout << "illegal argument" << endl;
            return true;
    }
    return false;
}

bool Graph::illegalWeightArgument(int weight){
    try{
        if(weight <= 0){
            throw illegal_exception();
        }
    }catch(illegal_exception){
            cout << "illegal argument" << endl;
            return true;
        }
    return false;
}

bool Graph::insert(int a, int b, int w){
    //check if a and b exist, add if don't
    // if both exist, return false
    //loop thru the focal point vertex's adj. list and add to all those as well.
    for(const auto& tuple : adjacencyList[a]){
        if(get<0>(tuple) == b){
            return false;
        }
    }
    adjacencyList[a].push_back(make_tuple(b, w));
    adjacencyList[b].push_back(make_tuple(a, w));
    return true;
}

void Graph::print(int a){
    for(const auto& tuple : adjacencyList[a]){
        cout << get<0>(tuple) << endl;
    }
}

bool Graph::del(int a){
    for(const auto& tuple1 : adjacencyList[a]){
        for(int i=0; i < adjacencyList[get<0>(tuple1)].size(); i++){
            if(get<0>(adjacencyList[get<0>(tuple1)][i]) == a){
                adjacencyList[get<0>(tuple1)].erase(adjacencyList[get<0>(tuple1)].begin() + i);
            }
        }
    }
    adjacencyList[a].erase(adjacencyList[a].begin(), adjacencyList[a].end());
}

void Graph::findMST(){
    PriorityQueue pQueue;
    pair<int,int> keyVectorPairs[500001];
    int cost = 0;
    int count = 0;
    //initialize first key to 0, all else to inf
    for(int i = 1; i < 500001; i++){
        if(adjacencyList[i].empty()){
            keyVectorPairs[i].first = -1;
        }else{
            count == 0 ? pQueue.keyVectorPairs[count] = make_pair(i,0) : pQueue.keyVectorPairs[count] = make_pair(i, INT_MAX);
            count++;
        }
    }
    pQueue.size = count;
    //select vertex with lowest cost relative to what's already in the graph
    //for each adjacent vertex to the chosen vertex, update the key (weight) value if it's smaller than the current one
    for(int i = 0; i < count; i++){
        pair<int,int> min = pQueue.findMin();
        mstCost += min.second;
        for(int j = 0; j < adjacencyList[min.first].size(); i++){
            if(adjacencyList[min.first][i].second <= pQueue.keyVectorPairs[0].second){
                keyVectorPairs[adjacencyList[min.first][i].first] = min.first;
                keyVectorPairs[adjacencyList[min.first][i].second] = min.second;
                pQueue.decreaseKey(adjacencyList[min.first][i].first, adjacencyList[min.first][i].second);
            }
        }
    }

    for(int i = 0; i<500001; i++){
        cout << i << " " << keyVectorPairs[i].first << " " << keyVectorPairs[i].second << " ";
    }
    cout << endl;
    
}

int Graph::cost(){
    return mstCost;
}