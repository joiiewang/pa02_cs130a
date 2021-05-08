#include <vector>
#include <string>
#include "minHeap.h"
#include "Node.h"
#include <iostream>
using namespace std;

Node* minHeap::getMin(){
    return v[0];
}

pair<string,Node*> minHeap::changeMin(string s, int c){
    string temp = v[0]->word;
    v[0]->word = s;
    v[0]->frequency++;
    v[0]->counter = c;
    int current =0;
    while(1){
        Node* rightChild = 2*current+2 < v.size() ? v[2*current+2] : nullptr;
        Node* leftChild = 2*current+1 <v.size() ? v[2*current+1] : nullptr;
        if(!rightChild && !leftChild) break;
        else if(!rightChild){
            if(v[current]->frequency>leftChild->frequency){
                //swap nodes
                Node* temp = v[current];
                v[current] = v[leftChild->index];
                v[leftChild->index] = temp;
                current = leftChild->index;
                //swapping index
                int num = leftChild->index;
                leftChild->index = temp->index;
                temp->index = num;
            }
            break;
            
        }
        else{
            Node* lowerFreq;
            if(leftChild->frequency<rightChild->frequency){
                lowerFreq = leftChild;
            }
            else if(leftChild->frequency==rightChild->frequency){
                lowerFreq = leftChild->counter<rightChild->counter ? rightChild:leftChild;
            }
            else lowerFreq = rightChild;

            if(lowerFreq->frequency<v[current]->frequency){
                Node* temp = v[current];
                v[current] = v[lowerFreq->index];
                v[lowerFreq->index] = temp;
                current = lowerFreq->index;

                //swapping index
                int num = lowerFreq->index;
                lowerFreq->index = temp->index;
                temp->index = num;

            }
            else break;
        }
    }

    return make_pair(temp,v[current]);
}

Node* minHeap::insert(string s, int c){
    Node* n = new Node(v.size(), s, 1, c);
    v.push_back(n);
    int compare = ((v.size()-1)-1)/2;
    int current = v.size()-1;
    if(v.size() > 1){
        while(v[current]->frequency <= v[compare]->frequency){
            Node* temp = v[compare];
            v[compare] = v[current];
            v[current] = temp;

            int num = temp->index;
            temp->index = v[compare]->index;
            v[compare]->index = num;

            current = compare;
            compare = (compare-1)/2;
            if(compare <= 0) break;
        }
    }
    
    return n;


}

void minHeap::increaseFrequency(Node* n){
    n->frequency++;
    //n->counter = c;
    int current = n->index;
    while(1){
        Node* rightChild = 2*current+2 < v.size() ? v[2*current+2] : nullptr;
        Node* leftChild = 2*current+1 <v.size() ? v[2*current+1] : nullptr;
        if(!rightChild && !leftChild) break;
        else if(!rightChild){
            if(v[current]->frequency>leftChild->frequency || v[current]->counter < leftChild->counter){
                //swap nodes
                Node* temp = v[current];
                v[current] = v[leftChild->index];
                v[leftChild->index] = temp;
                current = leftChild->index;
                //swapping index
                int num = leftChild->index;
                leftChild->index = temp->index;
                temp->index = num;
            }
            break;
        }
        else{
            Node* lowerFreq;
            if(leftChild->frequency<rightChild->frequency){
                lowerFreq = leftChild;
            }
            else if(leftChild->frequency==rightChild->frequency){
                lowerFreq = leftChild->counter<rightChild->counter ? rightChild:leftChild;
            }
            else lowerFreq = rightChild;

            if(lowerFreq->frequency<v[current]->frequency || (lowerFreq->frequency == v[current]->frequency && lowerFreq->counter > v[current]->counter)){
                Node* temp = v[current];
                v[current] = v[lowerFreq->index];
                v[lowerFreq->index] = temp;
                current = lowerFreq->index;

                //swap index
                int num = temp->index;
                temp->index = lowerFreq->index;
                lowerFreq->index = num;
            }
            else{
                break;
            }
        }
    }
}

void minHeap::removeMin(){
    v[0] = v[v.size()-1];
    v[0]->index = 0;
    v.pop_back();
    int current =0;
    while(1){
        Node* rightChild = 2*current+2 < v.size() ? v[2*current+2] : nullptr;
        Node* leftChild = 2*current+1 <v.size() ? v[2*current+1] : nullptr;
        if(!rightChild && !leftChild) break;
        else if(!rightChild){
            if(v[current]->frequency>leftChild->frequency || (v[current]->frequency == leftChild->frequency && v[current]->counter < leftChild->counter)){
                //swap nodes
                Node* temp = v[current];
                v[current] = v[leftChild->index];
                v[leftChild->index] = temp;
                current = leftChild->index;
                //swapping index
                int num = leftChild->index;
                leftChild->index = temp->index;
                temp->index = num;
            }
            break;
            
        }
        else{
            Node* lowerFreq;
            if(leftChild->frequency<rightChild->frequency){
                lowerFreq = leftChild;
            }
            else if(leftChild->frequency==rightChild->frequency){
                lowerFreq = leftChild->counter<rightChild->counter ? rightChild:leftChild;
            }
            else lowerFreq = rightChild;

            if((lowerFreq->frequency<v[current]->frequency)||
               (lowerFreq->frequency==v[current]->frequency&&lowerFreq->counter>v[current]->counter)){
                Node* temp = v[current];
                v[current] = v[lowerFreq->index];
                v[lowerFreq->index] = temp;
                current = lowerFreq->index;

                //swapping index
                int num = lowerFreq->index;
                lowerFreq->index = temp->index;
                temp->index = num;

            }
            else break;
        }
    }
}