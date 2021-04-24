#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename t>
void displayVector(vector<t> v) {
    for (int i = 0; i < v.size(); i++) {
        const t element = v[i];
        cout << element << " ";
    }
    cout << endl << "--" << endl;
}

vector<int> sortKSortedArray(const int k, vector<int> numbers) {
    priority_queue<int, vector<int>, greater<int> > maxHeap;
    int ptr = 0;

    for (int i = 0; i < numbers.size(); i++) {
        const int number = numbers[i];
        maxHeap.push(number);

        if (maxHeap.size() > k) {
            const int shortestNumber = maxHeap.top();
            numbers[ptr++] = shortestNumber;
            maxHeap.pop();
        }
    }

    while (ptr < numbers.size() && !maxHeap.empty()) {
            const int shortestNumber = maxHeap.top();
            numbers[ptr++] = shortestNumber;
            maxHeap.pop();
    }

    return numbers;
}

int main() {
    vector<int> numbers{6, 5, 3, 2, 8, 10};
    const int k = 3;
    const vector<int> sortedNumbers = sortKSortedArray(k, numbers);
    displayVector(sortedNumbers);
    return 0;
}