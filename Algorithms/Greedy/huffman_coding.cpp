#include<bits/stdc++.h>
using namespace std;
//Test Cases:
/*
INPUT:
a 5
b 9
c 12
d 13
e 16
f 45

OUTPUT:
f: 0
c: 100
d: 101
a: 1100
b: 1101
e: 111
*/

struct CharacterNode{
    char character;
    int frequency;
    //Constructors:
    CharacterNode(): character('$'), frequency(0) {}
    CharacterNode(char c, int f): character(c), frequency(f) {}
};

struct CharacterNodeComparator{
    bool operator()(CharacterNode a, CharacterNode b){ return a.frequency > b.frequency; }
}

void inputData(int size, vector<CharacterNode> &initialData){
    for( int i=0; i<6; i++ ){
        char character;
        int frequency;
        cin >> character >> frequency;
        CharacterNode cn = CharacterNode(character, frequency);
        initialData.push_back(cn);
    }
}

void displayVector(vector <CharacterNode> &data){
    cout << "Character" << "\t" << "Frequency" << endl;
    for(auto d = data.begin(); d != data.end(); d++){
        cout << d->character << "\t" << d->frequency << endl;
    }
    cout << endl;
}

vector<CharacterNode> minHeapifyData(vector<CharacterNode> &initialData){
    priority_queue <CharacterNode, vector<CharacterNode>, CharacterNodeComparator> minHeap; 

    for( ini = initialData.begin(); ini != initialData.end(); ini++ ){
        minHeap.push(*ini);
    }

    return minHeap;
}



int main(){
    int size = 6;
    vector<CharacterNode> initialData;

    return 0;
}