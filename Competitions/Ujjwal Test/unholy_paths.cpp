#include <bits/stdc++.h>
using namespace std;

int Solution(vector<int> thieves, vector<vector <int> > edges) {

}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;

    vector<vector<int>> edges(n - 1, vector<int>(2));
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> edges[i][j];
        }
    }

    vector<int> thieves(k);
    for (int i = 0; i < k; i++) {
        cin >> thieves[i];
    }

    cout << Solution(thieves, edges) << endl;
    return 0;
}