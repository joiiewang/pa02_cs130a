#include <iostream>
using namespace std;
#include "minHeap.h"
#include "Node.h"
#include "hashTable.h"
#include <fstream>
#include <cstdlib>

int main(int argc, char* argv[]){
    ifstream myFile(argv[1]);
    if(!myFile.is_open()) throw runtime_error("could not open file");
    int k = atoi(argv[3]);
    string line;
    minHeap m;
    hashTable h(k);
    int total_words = 0;
    int counter =0;

    while(getline(myFile, line, ',')){
        if(h.getWord(line)){
            Node* n = h.getWord(line);
            /*for(int i=0;i<m.v.size();i++){
                cout<<m.v[i]->word<<","<<m.v[i]->frequency<<endl;
            }*/
            m.increaseFrequency(n);

        }
        else{
            if(total_words<k){
                Node* temp = m.insert(line, counter);
                total_words++;
                h.insert(line, temp);
                /*for(int i=0; i<h.v.size(); i++){
                    cout << h.v[i].first << endl;
                }
                cout<<"_____________________"<<endl;*/
            }
            else if(total_words==k){
                pair<string, Node*> p = m.changeMin(line, counter);
                h.remove(p.first);
                h.insert(line, p.second);
                /*for(int i=0; i<h.v.size(); i++){
                    cout << h.v[i].first << endl;
                }
                cout<<"_________''____________"<<endl;*/                
            }
            counter++;
        }
    }

    ofstream output;
    output.open(argv[2]);
    while(m.v.size()>0){
        //cout<<m.getMin()->word+","+m.v[m.getMin()->index]->word<<endl;
        output<< m.getMin()->word + ":" +to_string(m.getMin()->frequency)+ ",";
        //output<< m.getMin()->word + ":" +to_string(m.getMin()->frequency)+ '(' + to_string(m.getMin()->counter) + ')' + ",";
        m.removeMin(); 
    }
    /*for(int i=0;i<m.v.size();i++){
        output<<m.v[i]->word + ":" +to_string(m.v[i]->frequency)+",";
    }*/
   /* for(int i=0; i<h.v.size(); i++){
        string s = h.v[i].second ? h.v[i].second->word : "";
        cout << h.v[i].first << ',' << s <<  endl;
    }*/
    //cout << h.getWord("4")->counter << endl;
    output.close();

    return 0;
}