#include <bits/stdc++.h>
using namespace std;

int getAliceScore(const string &s) {
    const int l = s.length();
    int alice = 0, bob = 0;
    priority_queue<int> consecutiveOnes;
    int consecutive;

    if (s[0] == '0') consecutive = 0;
    else consecutive = 1;

    //Traverse the whole string and make the priority queue
    for (int i = 1; i < l; i++) {
        if (s[i] == '1') consecutive++;
        else if (s[i] == '0') {
            if (s[i - 1] == '1') consecutiveOnes.push(consecutive);
            consecutive = 0;
        }
    }
    if (s[l - 1] == '1')
        consecutiveOnes.push(consecutive);

    //Finding out the scores
    short int f = -1;
    while (!consecutiveOnes.empty()) {
        int score = consecutiveOnes.top();
        consecutiveOnes.pop();

        if (f == -1) alice += score;
        else bob += score;

        f *= -1;
    }

    return alice;
}

int main() {
    int t; cin >> t;
    while (t --) {
        string s;
        cin >> s;
        cout << getAliceScore(s) << endl;
    }
    return 0;
}