#include <bits/stdc++.h>
using namespace std;

int kthSmallestElement(const int k, const vector<int> numbers) {
    priority_queue<int> maxHeap;

    for (const int number: numbers) {
        maxHeap.push(number);
        // Pop the top element if the size if greater then k
        if (maxHeap.size() > k)
            maxHeap.pop();
    }

    return maxHeap.top();
}

void printKthLargestElements(const int k, const vector<int> numbers) {
    priority_queue<int, vector<int>, greater<int> > minHeap;

    for (const int number: numbers) {
        minHeap.push(number);
        // Pop the top element if the size if greater then k
        if (minHeap.size() > k)
            minHeap.pop();
    }

    cout << k << "largest numbers: " << endl;
    while (!minHeap.empty()) {
        const int number = minHeap.top();
        minHeap.pop();
        cout << number << " ";
    }
    cout << endl << "--" << endl;
}

int main() {
    vector<int> numbers{7, 10, 4, 3, 20, 15};
    const int k = 3;
    cout << k << "th smallest number: " << kthSmallestElement(k, numbers) << endl;
    return 0;
}