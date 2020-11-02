#include <bits/stdc++.h>
using namespace std;

int findSmallestDivisor(string s, string t) {
    const int NOT_FOUND = -1;

    // Check if t is divisible by s or not
    // First check that is T substring of s:
    if (s.find(t) != string::npos) {
        // Now loop through temp t to find whether t is divsible:
        string temp_t = t;

        while (true) {
            if (temp_t.length() == s.length() && temp_t == s) break;
            if (temp_t.length() > s.length()) return NOT_FOUND;
            // Append t into temp_t
            else {
                temp_t += t;
            }
            
        }
    } else {
        return NOT_FOUND;
    }

    // Reached till here it means possibility of finding u also:
    string u(t.begin(), t.begin() + 1);
    int counter = 1;
    while (true) {
        if (u.length() == t.length() && u == t) return u.length();
        if (u.length() > t.length()) return NOT_FOUND;
        // Append t into u
        else {
            u += t[counter++];
            // Now loop through temp t to find whether t is divsible:
            string temp_u = u;

            while (true) {
                if (temp_u.length() == t.length() && temp_u == t) return u.length();
                if (temp_u.length() > s.length()) break;
                // Append t into temp_t
                else {
                    temp_u += u;
                }
            }
        }
        
    }

    return NOT_FOUND;
}

int main() {
    string t = "lrbb";
    string s = "lrbblrbb";
    cout << findSmallestDivisor(s, t) << endl;
    return 0;
}