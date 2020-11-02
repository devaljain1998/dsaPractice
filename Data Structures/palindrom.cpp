#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &s) {
    int length = s.length();
    for (int i = 0; i < length / 2; i++) {
        if (s[i] != s[length - 1 - i]) {
            return false;
        }
    }
    return true;
}

void countFrequency(int* a, int n) {
    bool counted[n] = {false};

    for (int i = 0; i < n; i++) {
        int number = a[i];
        // if the number is not counted then only loop
        // otherwise just continue
        if (counted[i] == false) {
            int count = 1;
            for (int j = i + 1; j < n; j++) {
                if (a[j] == number) {
                    counted[j] = true;
                    count++;
                }
            }
            cout << "Frequency of number: " << number << " : " << count << endl;
        }
    }

    return;
}

int main() {
    string s = "Malayalam";
    // cout << isPalindrome(s) << endl;
    int a[11] = {2, 1, 2, 2, 2, 3, 4, 5, -1, 2, 2};
    countFrequency(a, 11);
    return 0;
}