#include <bits/stdc++.h>
using namespace std;

#define NOT_FOUND "-1"
#define endl "\n"

inline string getReturnString(const long int &a, const long int &b, const long int &c) {
    return to_string(a) + " " + to_string(b) + " " + to_string(c);
}

inline bool isTriangle(const long int &a, const long int &b, const long int &c) {
    return ((a + b > c) && (b + c > a) && (a + c > b));
}

string getBadTriplets(const vector<long int> &v) {
    if (v.size() <= 2) return NOT_FOUND;
    if (v.size() == 3) return isTriangle(v[0], v[1], v[2]) ? NOT_FOUND : getReturnString(0, 1, 2);

    int pivot = 0, left = pivot + 1, right = v.size() - 1;

    return isTriangle(v[pivot], v[left], v[right]) ? NOT_FOUND : getReturnString(pivot, left, right);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long int> num(n);
        for (int i=0; i < n; i ++) {
            cin >> num[i];
        }
        if (num[0] + num[1] <= num[n - 1]) 
            cout << 1 << " " << 2 << " " << n << endl;
        else
            cout << NOT_FOUND << endl;
    }
    return 0;
}