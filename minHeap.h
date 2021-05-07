#ifndef MINHEAP_H
#define MINHEAP_H
#include "Node.h"
#include <vector>

class minHeap{
    public:
        minHeap(){
            
        }
        std::vector<Node*> v;
        Node* insert(std::string s, int c);
        void increaseFrequency(Node* n);
        std::pair<std::string, Node*> changeMin(std::string s, int c);
        Node* getMin();
        void removeMin();

};

#endif