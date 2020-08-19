#include<bits/stdc++.h>
using namespace std;
//INCOMPLETE ------>
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
    CharacterNode *left_ptr = NULL, *right_ptr = NULL;
    //Constructors:
    CharacterNode(): character('$'), frequency(0) {}
    CharacterNode(char c, int f): character(c), frequency(f) {}
    CharacterNode(char c, int f, CharacterNode a, CharacterNode b): character(c), frequency(f), left_ptr(&a), right_ptr(&b) {}
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

void minHeapifyData(vector<CharacterNode> &initialData){
    priority_queue <CharacterNode, vector<CharacterNode>, CharacterNodeComparator> minHeap; 

    for( ini = initialData.begin(); ini != initialData.end(); ini++ ){
        minHeap.push(*ini);
    }
    auto ini = initialData.begin();
    for( auto minElement = minHeap.begin(); minElement != minHeap.end(); minElement++, ini++ ){
        *ini = *minElement;
    }

}

void getHuffmanCodes(vector<CharacterNode> initialData){

}

int main(){
    int size = 6;
    vector<CharacterNode> initialData;
    inputData(size, initialData);
    displayVector(initialData);
    return 0;
}