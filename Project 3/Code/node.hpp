#ifndef node
#define node

class Node {
    public:
        Node* children[26];
        bool endWord;
        Node();
        ~Node();
        void setChild(Node* child, int index);
        Node *getChild(int index);
        void setEndWord(bool isEndWord);
        bool hasChild();
        bool getEndWord();
};
#endif