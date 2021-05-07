#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Node.h"
#include <vector>
#include <functional>

class hashTable{
    public:
        hashTable(int k);
        std::hash<std::string> hash_string;
        std::vector<std::pair<std::string, Node*>> v;
        Node* getWord(std::string s);
        void remove(std::string s);
        void insert(std::string s, Node* n);

};

#endif