#ifndef NODE_H
#define NODE_H

class Node{
    public:
        Node(int i, std::string s, int f, int c){
            this->index=i;
            this->word = s;
            this->frequency = f;
            this->counter = c;
        }
        int index;
        std::string word;
        int frequency;
        int counter;
};

#endif