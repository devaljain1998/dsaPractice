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

int main() {
    vector<int> numbers{7, 10, 4, 3, 20, 15};
    const int k = 3;
    cout << k << "th smallest number: " << kthSmallestElement(k, numbers) << endl;
    return 0;
}