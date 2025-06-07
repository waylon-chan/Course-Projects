#include <iostream>
#include <string>
#include <fstream>
#include "priorityqueue.hpp"
#include "graph.hpp"
#include "illegal_exception.hpp"

using namespace std;

int main(){
    string cmd;
    Graph graph;
    PriorityQueue priorityQueue;
    int a,b,w;
    while(cin >> cmd){
        if(cmd == "LOAD"){
            string fileName;
            cin >> fileName;
            ifstream fin(fileName.c_str());

            //cout << "success" << endl;
        }else if(cmd == "INSERT"){
            cin >> a >> b >> w;
            if(!graph.illegalVertexArgument(a)){
                //success
            }
            if(!graph.illegalVertexArgument(b)){
                //success
            }
            if(!graph.illegalWeightArgument(w)){
                //success
            }
        }else if(cmd == "PRINT"){
            cin >> a;
            if(!graph.illegalVertexArgument(a)){
                //success
            }
        }else if(cmd == "DELETE"){
            cin >> a;
            if(!graph.illegalVertexArgument(a)){
                //success
            }
        }else if(cmd == "MST"){

        }else if(cmd == "COST"){

        }else{
            break;
        }
    }
    return 0;
};