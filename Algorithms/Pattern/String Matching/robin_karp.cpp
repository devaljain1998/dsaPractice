#include <bits/stdc++.h>
using namespace std;

//NOTE: Haven't tested the program yet

int hashTable[256];

bool patternThroughRobinKarp(const string &text, const string &pattern);
long hashFunction(string pat, long modulo);
long reHash(long hash, char prev, char current, string pattern, long modulo);

void fillHashTable(){
    for(int i=0; i<256; i++){
        hashTable[i] = i;
    }
}

int main(int argc, char** argv){
    fillHashTable();
    return 0;
}

bool patternThroughRobinKarp(const string &text, const string &pattern){
    long modulo = 1000000000000001;
    auto pattern_hash_value = hashFunction(pattern, modulo);
    string current_string(text, 0, pattern.length()-1);
    auto current_hash_value = hashFunction(current_string, modulo);

    bool found = false;
    vector <int> indices;

    if(pattern_hash_value ==  current_hash_value){ indices.push_back(0); found=true; }

    for(int i=pattern.length(); i<text.length()-pattern.length()+1; i++){
        current_hash_value = reHash(current_hash_value, text[i-pattern.length()], text[i], pattern, modulo);
        if(current_hash_value == pattern_hash_value){
            current_string = string(text, i, pattern.length()-1);

            if(current_string == pattern){
                found = true;
                indices.push_back(i);
            }
        }
    }

    return found;
}

long hashFunction(const string &pat,const long modulo){
    long hash_value = 0;
    for(int i=0; i<pat.length(); i++){
        hash_value = (hash_value*256 + hashTable[pat[i]])%modulo;
    }
    return hash_value;
}

long reHash(long hash, char prev, char current, const string &pat, long modulo){
    auto new_hash_value = ((hash*256 - long(pow(int(prev), pat.length()-1)))%modulo + hashTable[current])%modulo ;
    return new_hash_value;
}