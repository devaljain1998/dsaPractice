#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename t>
void displayVector(vector<t> v, const string& vectorName = "") {
    cout << "Vector: " << vectorName << endl;
    for (int i = 0; i < v.size(); i++) {
        const t element = v[i];
        cout << element << " ";
    }
    cout << endl << "--" << endl;
}

template<typename t1, typename t2>
void displayMap(map<t1, t2> m, const string& mapName) {
    cout << "map: " << mapName << endl;
    for (auto ele: m) {
        cout << ele.first << ": " << ele.second << endl;
    }
    cout << endl << "--" << endl;
}


vector<int> kFrequentNumbers(const int k, const vector<int> numbers) {
    map<int, int> frequency;
    for (int i = 0; i < numbers.size(); i++) {
        frequency[numbers[i]]++;
    }
    displayMap(frequency, "frequency");
    return vector<int>(frequency.begin(), frequency.begin() + k);
}


int main() {
    vector<int> numbers{1, 1, 2, 3, 2, 1, 4, 5, 4, 4, 4, 4};
    const int k = 3;
    kFrequentNumbers(k, numbers);
    return 0;
}