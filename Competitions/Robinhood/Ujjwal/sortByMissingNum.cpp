#include<bits/stdc++.h>
using namespace std;

int findMissingNumber(vector<vector<string> > &square) {
    pair<int, int> questionPoint;
    int missing;

    // Initializing a Hashmap till value 16
    map<int, bool> map{
        {1, false}, {2, false}, {3, false}, {4, false},
        {5, false}, {6, false}, {7, false}, {8, false},
        {9, false}, {10, false}, {11, false}, {12, false},
        {13, false}, {14, false}, {15, false}, {16, false}
    };

    //iterating over the map to find the missing number:
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (square[i][j] == '?') {
                questionPoint.first = i;
                questionPoint.second = j;
            }
            map[square[i][j]] = true;
        }
    }

    //returning the not found
    for (auto num: map) {
        if (num.second == false) {
            missing = num.first;
        }
    }

    square[questionPoint.first][questionPoint.second] = missing;

    return missing;
}

vector <vector<string>> getSquareMatrix(const vector<vector<string> > &mat, 
    const int &start) {
    //Created a square matrix
    vector <vector <string>> square(4, vector<string> (4));

    //Filling values:
    for (int i = 0; i < 4; i++) {
        for (int j = start; j < start + 4; j++) {
            square[i][j] = mat[i][j];
        }
    }

    return square;
}

void refillMatrix(vector<vector<string> > &mat, const vector< vector<string>> &squares,
    vector< pair<int, int>> &missingAndStart) {
    
    vector <string> row1;
    vector <string> row2;
    vector <string> row3;
    vector <string> row4;

    // iterating through every row of every square:
    for (auto p : missingAndStart) {
        int start = p.second;
        int missing = p.first;

        for (int i = start; i < start + 4; i++) {
            row1.push_back( mat[0][i] != "?" : mat[0][i] ? missing );
            row2.push_back( mat[1][i] != "?" : mat[1][i] ? missing );
            row3.push_back( mat[2][i] != "?" : mat[2][i] ? missing );
            row4.push_back( mat[3][i] != "?" : mat[3][i] ? missing );
        }
    }

    mat[0] = row1;
    mat[1] = row2;
    mat[2] = row3;
    mat[4] = row4;

    return;
}

vector<vector<string> > sortByMissingNum(vector<vector<string> > mat) {
    vector< vector<string>> squares;
    vector< pair<int, int>> missingAndStart;

    for (int i =0; i < mat[0].size(); i += 4) {
        auto square = getSquareMatrix(mat, i);
        squares.push_back(square);

        int missing = findMissingNumber(square);
        int start = i;

        missingAndStart.push_back(make_pair(missing, start));
    }

    //sorting the pair:
    sort(missingAndStart.begin(), missingAndStart.end());

    //refilling the mat
    refillMatrix(mat, squares, missingAndStart);

    return mat;
}

void test() {
    vector <vector<string>> mat{
        {"1"}, {"2"}, {"3"}, {"4"},
        {"?"}, {"6"}, {"7"}, {"8"},
        {"9"}, {"10"}, {"11"}, {"12"},
        {"13"}, {"14"}, {"15"}, {"16"}
    };
    vector <vector<string>> ans{
        {"1"}, {"2"}, {"3"}, {"4"},
        {"11"}, {"6"}, {"7"}, {"8"},
        {"9"}, {"10"}, {"11"}, {"12"},
        {"13"}, {"14"}, {"15"}, {"16"}
    };
    assert(sortByMissingNum(mat) == mat);
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}
