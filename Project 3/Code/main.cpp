#include <iostream>
#include <string>
#include <fstream>
#include "trie.hpp"

using namespace std;

int main(){
    Trie trie;
    string cmd, word, prefix;
    while(cin >> cmd){
        if(cmd == "load"){
            ifstream fin("corpus.txt");
            while(fin >> word){
                trie.insert(word);
            }
            cout << "success" << endl;
        }else if(cmd == "i"){
            cin >> word;
            if(trie.insert(word)){
                cout << "success" << endl;
            }else{
                cout << "failure" << endl;
            }
        }else if(cmd == "e"){
            cin >> word;
            if(trie.erase(word)){
                cout << "success" << endl;
            }else{
                cout << "failure" << endl;
            }
        }else if(cmd == "c"){
            cin >> prefix;
        }else if(cmd == "p"){
            trie.printTrie();
        }else if(cmd == "empty"){
            trie.isEmpty();
        }
    }
    return 0;
}