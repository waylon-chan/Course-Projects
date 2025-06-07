#include <iostream>
#include "linkedlist.hpp"

using namespace std;

int main() { 
    LinkedList* calculator = nullptr;
	string cmd;
	while(cin >> cmd){
		if(cmd == "CRT"){
            int n; 
			cin >> n;
			calculator = new LinkedList(n);
			cout << "success" << endl;
		}else if(cmd == "DEF"){
            string name;
            double value;  
			cin >> name >> value;
			if(calculator->def(name, value)){
                cout << "success" << endl;
            }else{
                cout << "failure" << endl;
            }
		}else if(cmd == "ADD"){
            string x, y, z; 
			if(calculator->add(x, y, z)){
                cout << "success" << endl;
            }else{
                cout << "failure" << endl;
            }
		}else if(cmd == "SUB"){
            string x, y, z; 
			if(calculator->sub(x, y, z)){
                cout << "success" << endl;
            }else{
                cout << "failure" << endl;
            }
		}else if(cmd == "REM"){
            string x; 
			if(calculator->rem(x)){
                cout << "success" << endl;
            }else{
                cout << "failure" << endl;
            }
		}else if(cmd == "PRT"){
            string x; 
            cin >> x;
            calculator->prt(x);
		}else{
            break;
        }
	}
	delete calculator;
	return 0;
}