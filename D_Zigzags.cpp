#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        map<int, int> count;

        for (auto num : a) {
            count[num]++;
        }
        int tuples = 0;
        for (auto number : count) {
            if (number.second >= 4) {
                tuples += ((int)(number.second / 4)); // number.second C 4
            }
        }
        cout << tuples << endl;
    }
    return 0;
}