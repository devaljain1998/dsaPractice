#include <bits/stdc++.h>
using namespace std;

/*
Input : arr[] = {10, 5, 11, 6, 20, 12}
Output: 5, -1, 6, -1, 12, -1

stack: v:
[]  [-1]
[12] [-1, 12]
[20 12] [-1 12] => [] [-1 12 -1]
[6] [-1 12 -1 6]
[11 6] [-1 12 -1 6] => [] [-1 12 -1 6 -1]
[5] []
            }{S}POutput : -1, 10, -1, 10, -1, 20
*/

vector<int> getNearestSmallerToTheRight(const vector<int>& v) {
    vector<int> smaller(v.size());

    // Constants:
    const int NOT_FOUND = -1;

    // Main Code:
    stack<int> s;

    for (int i = v.size() - 1; i >= 0; i--) {
        if (s.empty()) {
            smaller[i] = NOT_FOUND;
        }
        else if (s.top() < v[i]) {
            smaller[i] = s.top();
        }
        else {
            while (!s.empty() && s.top() < v[i]) s.pop();

            if (s.top() < v[i])
                smaller[i] = s.top();
            else
                smaller[i] = -1;
        }
        s.push(v[i]);
    }

    return smaller;
}

void displayVector(const string& name, const vector<int>& v) {
    cout << name << endl;
    for (int i = 0; i < v.size(); i++) {
        const int num = v[i];
        cout << num << " ";
    }
    cout << endl << "--" << endl;
}

int main() {
    int a[] = {10, 5, 11, 6, 20, 12};
    vector<int> v(a, a+6);
    vector<int> nsr = getNearestSmallerToTheRight(v);
    displayVector("original", v);
    displayVector("output: ", nsr);
    return 0;
}