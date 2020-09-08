#include <bits/stdc++.h>
using namespace std;

vector<int> nsl(vector<int> v) {
    if (v.size() == 0) return vector<int>{};
    if (v.size() == 1) return vector<int>{-1};

    //vector to store nearest smaller elements
    vector<int> nearestSmallerElements(v.size());
    // Initializing stack
    stack<int> s;

    for (int i = 0; i < v.size(); i++) {
        if (s.empty())
            nearestSmallerElements[i] = -1;
        else if (s.top() < v[i])
            nearestSmallerElements[i] = s.top();
        else {
            // Popping the elements from the stack untill
            // the stack is empty
            // or the top element is greater than the current element
            while (!s.empty() && s.top() >= v[i]) s.pop();

            // if stack is empty then mark the element as -1
            if (s.empty()) nearestSmallerElements[i] = -1;
            // else mark the element with the current top
            else if (s.top() < v[i]) nearestSmallerElements[i] = s.top();
        }
        s.push(v[i]);
    }

    return nearestSmallerElements;
}

int main() {
    vector<int> v{4, 5, 2, 10, 8};
    auto result = nsl(v);
    for (auto n : result) {
        cout << n << ", ";
    } cout << endl;
    return 0;
}