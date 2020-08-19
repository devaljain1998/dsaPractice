#include<bits/stdc++.h>
using namespace std;

void display(vector<vector <int> > matrix) {
    for (auto row: matrix) {
        for (auto n: row) {
            cout << n << ", ";
        }
        cout << endl;
    }
}

void buildPattern(vector<vector <int> > matrix, const int n) {
    const int size = matrix.size();
    int j;

    for (int i = 0; i < size; i++) {
        int numberToBePrinted = n - i;
        for (j = i; j < size - i; j++) {
            matrix[i][j] = matrix[size - 1 - i][j] = numberToBePrinted;
        }
        j = size - 1 - i;
        for (int k = i; k < size - i; k++) {
            matrix[k][j] = matrix[k][i] = numberToBePrinted;
        }
        //cout << i + 1 << endl;display(matrix); cout << endl;
    }
}

int main() {
    int n = 4;
    vector<vector <int> > matrix(2*n - 1, vector<int>(2*n - 1));
    buildPattern(matrix, n);
}