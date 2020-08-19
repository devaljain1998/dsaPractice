#include <bits/stdc++.h>
using namespace std;

const char ADD = '+';
const char SUBTRACT = '-';

const string YES = "YES", NO = "NO";

int discarded;
bool isSquare = false;

bool canRectangleBeMade(map<int, int> &woods, int &sum) {
    if (sum < 4) return false;
    if (sum == 4 && !(woods.size() == 1 || woods.size() == 2)) return false;

    bool oneSide = false;

    //Rectange can be made if:
    // 1 side has more than for number
    // 2 sides has greater then 2 number
    for (auto wood: woods) {
        if (wood.second >= 4) {
            return true;
        } else if (oneSide && wood.second >= 2) {
            return true;
        } else if (wood.second >= 2 && !oneSide) {
            oneSide = true;
        }
    }

    return false;
}

bool canSquareBeMade(map<int, int> &woods, int &sum) {
    if (sum < 4) return false;
    if (sum == 4 && woods.size() != 1) return false;

    for (auto wood: woods) {
        if (wood.second >= 4) {
            woods[wood.first] -= 4;
            sum -= 4;
            discarded = wood.first;
            return true;
        }
    }
    return false;
}

bool findPossibility(map<int, int> &wood, int &sum) {
    if (sum < 8) {
        isSquare = false;
        return false;
    }

    bool square = canSquareBeMade(wood, sum);
    if (!square) {
        isSquare = false;
        return false;
    } else isSquare = true;

    bool rectange = canRectangleBeMade(wood, sum);
    return square && rectange;
}

void updateStock(const char &operation, const int &newWood, map<int, int> &wood, int &sum) {
    if (operation == ADD) {
        wood[newWood]++;
        sum++;
    }
    else {
        if (wood[newWood] >= 1) wood[newWood]--;
        sum--;
    }
    return;
}

int main() {
    int n, sum = 0;
    cin >> n;
    int newWood;

    map<int, int> wood;
    for (int i = 0; i < n; i++) {
        cin >> newWood;
        wood[newWood]++;
        sum++;
    }

    int q;
    cin >> q;
    
    char operation;

    while(q--) {
        cin >> operation >> newWood;
        //Updating the exisiting stock
        updateStock(operation, newWood, wood, sum);
        
        //Finding possibility:
        bool isPossible = findPossibility(wood, sum);
        if (isPossible) cout << YES << "\n";
        else cout << NO << "\n";
        if (isPossible || isSquare) {
            wood[discarded] += 4;
            sum += 4;
            isSquare = false;
        }
    }

    return 0;
}