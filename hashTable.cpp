#include <vector>
#include <string>
#include <functional>
#include "hashTable.h"
#include "Node.h"
#include <iostream>
using namespace std;

bool KisNotPrime(int k){
    for(int i=2;i<k/2;i++){
        if(k%i==0) return true;
    }
    return false;
}

hashTable::hashTable(int k){
            k*=2;
            while(KisNotPrime(k)){
                k++;
            }
            pair<string, Node*> p;
            for(int i=0;i<k;i++){
                v.push_back(p);
            }
        }

Node* hashTable::getWord(string s){
    int hash = hash_string(s)%v.size();
    //cout << s << ',' << hash << endl;
    int addOn = 0;
    int temp = hash;

    while(v[temp].first!=""){
        temp = hash+addOn*addOn;
        if(temp>v.size()-1){
            temp = temp - v.size()-1;
        }
        if(v[temp].first == s) return v[temp].second;
        addOn++;
    }
    return NULL;


}

void hashTable::remove(string s){
    int hash = hash_string(s)%v.size();
    //cout << s << ',' << hash << endl;
    int addOn = 0;
    int temp = hash;

    while(1){
        temp = hash+addOn*addOn;
        if(temp>v.size()-1){
            temp = temp - v.size()-1;
        }
        if(v[temp].first == s){
            v[temp].first ="REMOVED";
            v[temp].second =NULL;
            break;
        }
        addOn++;
    }
}

void hashTable::insert(string s, Node*n){
    int hash = hash_string(s)%v.size();
    //cout << s << ',' << hash << endl;
    int addOn = 0;
    int temp = hash;

    while(1){
        temp = hash+addOn*addOn;
        if(temp>v.size()-1){
            temp = temp - v.size()-1;
        }
        if(v[temp].first == "" || v[temp].first == "REMOVED"){
            v[temp].first =s;
            v[temp].second =n;
            break;
        }
        addOn++;
    }
}