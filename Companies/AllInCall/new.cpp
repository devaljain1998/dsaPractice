#include <bits/stdc++.h>
using namespace std;
// Base Cases:
// 1 1
// 1 1

// 1 0
// 0 1

// 0 0
// 1 1

// 0 1
// 1 1

// 1 1 1
// 1 0 1
// 1 1 1

// 1 1 0 0
// 1 1 0 0
// 0 0 1 1

void breadthFirstSearch(const vector <vector <int> > &matrix, vector< vector<bool>> &visited, int &i, int &j) {
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    while (!q.empty()) {
        pair<int, int> point = q.front();

        // Mark the point visited:
        visited[point.first][point.second] = true;

        // UP
        if (point.first - 1 >=0 && matrix[point.first - 1][point.second] == 1) q.push(make_pair(point.first - 1, point.second));
        // Down
        if (point.first + 1 <= (matrix.size() - 1) && matrix[point.first + 1][point.second] == 1) q.push(make_pair(point.first + 1, point.second));
        // Right
        if (point.second + 1 <= (matrix[0].size() - 1) && matrix[point.first][point.second + 1] == 1) q.push(make_pair(point.first, point.second + 1));
        // Left
        if (point.second - 1 >= 0 && matrix[point.first][point.second - 1] == 1) q.push(make_pair(point.first, point.second - 1));

        q.pop();
    }
    return;
}

int getComponents(vector <vector <int> > &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int components = 0;
    // A matrix to keep count of the visited nodes:
    vector< vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { 
            if (matrix[i][j] == 1 && !visited[i][j]) {
                components++;
                breadthFirstSearch(matrix, visited, i, j);
            }
        }
    }
    return components;
}

int main() {
    int n, m; cin >> n >> m;
    vector <vector <int> > matrix(n, vector<int>(m));
    //Input matrix:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << getComponents(matrix);
    return 0;
}