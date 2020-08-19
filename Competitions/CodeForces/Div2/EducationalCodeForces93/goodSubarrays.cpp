#include <bits/stdc++.h>
using namespace std;

inline int subarrayLength(const int &left, const int &right) {
    return right - left + 1;
}

inline void rollingSum(const int &left, const vector<int> &v, const int &right, int &sum) {
    sum = sum - v[left - 1] + v[right];
}

int getInitialSum(const int &left, const int &right, const vector<int> &v) {
    return accumulate(v.begin(), v.begin() + right + 1, 0);
}

int getGoodSubarrays(const vector<int> &v) {
    if (v.size() == 0) return 0;
    if (v.size() == 1) return v[0] == 1 ? 1 : 0;

    int goodSubarrays = 0;
    int subarraySize = 1;
    int left = 0, right = 1;
    const int n = v.size();

    for (;subarraySize <= n; subarraySize++) {
        int sum = 0;
        for (left = 0, right = left + subarraySize - 1; left <= n - subarraySize; left++, right++) {
            if (left == 0) sum = getInitialSum(left, right, v);
            else if (subarraySize == 1) sum = v[left];
            else rollingSum(left, v, right, sum);

            if (sum == subarraySize) goodSubarrays++;
        }
    }

    return goodSubarrays;
}

vector<int> getVectorFromString(const string &s, const int &n) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = s[i] - '0';
    }
    return v;
}

int main(int argc, char const *argv[])
{
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        auto v = getVectorFromString(s, n);
        cout << getGoodSubarrays(v) << endl;
    }
    return 0;
}
