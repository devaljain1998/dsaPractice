#include <bits/stdc++.h>
using namespace std;

/*
EXAMPLES:

PROCEDURE:
    1. initialization:
        matrix[v.size() + 1][sum + 1]
        i == 0 => False, j == 0 => True
    2. process:
        for (int i = 0; i <= v.size(); i++)
            for (int currentSum = 0; currentSum <= sum; currentSum++) {
                node = v[i]

                if (node <= currentSum)
                                            INCLUDE                          || EXCLUDE
                    memory[i][currentSum] = memory[i - 1][currentSum - node] ||     memory[i - 1][currentSum]
                else
                    EXCLUDE
                    memory[i][currentSum] = memory[i - 1][currentSum]
            }

    3. return memory[v.size()][sum]
*/
typedef vector< vector<bool> > matrix;

void displayMatrix(matrix &m) {
    for (auto row: m) {
        for (auto col: row) {
            cout << col << " ";
        }
        cout << endl;
    }
    cout << "--\n";
}

bool subsetSum(const vector<int>& v, const int& sum) {
    const int size = v.size();
    vector< vector<bool> > m(v.size() + 1, vector<bool>(sum + 1, false));

    for (int i = 0; i <= size; i++) {
        for (int j = 0; j <= sum; j++) {
            // Initialization:
            if (i == 0 && j != 0) {
                m[i][j] = false;
                continue;
            } else if (j == 0) {
                m[i][j] = true;
                continue;
            }

            // Process:
            // Valid
            const int num = v[i - 1];
            if (num <= j) {
                m[i][j] = m[i - 1][j - num] // Include
                            ||
                          m[i - 1][j]; // Exclude
            } 
            // Invalid:
            else {
                m[i][j] = m[i - 1][j]; // Exclude
            }
        }
    }
    displayMatrix(m);
    return m[size][sum];
}

int main() {
    const vector<int> v{1, 2, 3, 4};
    const int sum = 7;
    cout << subsetSum(v, sum) << endl;
    return 0;
}