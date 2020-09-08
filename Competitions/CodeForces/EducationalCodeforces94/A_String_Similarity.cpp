#include <bits/stdc++.h>
using namespace std;
#define pb push_back

/*
find n (n = (string.size() + 1) / 2)
generate substrings
make a isSimilarFunction
get a stringw
    make a container in which all the substrings are placed and marked as false
    loop untill all the strings are similar
    if (after loop the size of the stirng is not n) then make the stirng to size n makeStringToSizeN
    return string
*/

struct SimilarString {
public:    
    string s;
    bool similar;

    SimilarString(){}

    SimilarString(string s, bool similar) {
        this->s = s;
        this->similar = similar;
    }
};

bool isSimilar(const string &a, const string &b) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) return true;
    }
    return false;
}

vector<SimilarString> getSubstrings(const string &s, const int &n) {
    vector<SimilarString> substrings(n);
    for (int i = 0; i < n; i++) {
        auto substring = s.substr(i, n);
        SimilarString ss(substring, false);
        substrings[i] = ss;
    }
    return substrings;
}

string getSimilarString(vector<SimilarString> &substrings, const int &n) {
    if (n == 1) return substrings[0].s;
    
    string similar;

    for (int i = 0; i < n; i++) {
        char c;
        int count_zero = 0, count_one = 0;
        for (int j = 0; j < n; j++) {
            //Increase the count_zero
            //Mark the corresponding string as similar
            if (substrings[j].s[i] == '0' && substrings[j].similar == false) {
                count_zero++;
                substrings[j].similar = true;
            } else 
            if (substrings[j].s[i] == '1' && substrings[j].similar == false) {
                count_one++;
                substrings[j].similar = true;
            }

        }
        if (count_zero >= count_one) c = '0';
        else c = '1';

        similar += c;
    }

    return similar;
}

void solve(const string &s, const int &n){
    auto substrings = getSubstrings(s, n);
    auto similar = getSimilarString(substrings, n);
    cout << similar << endl;
}

int main(){
    int t = 0;
    cin >> t;
    while(t--) {       
        int n; cin >> n;
        string s; cin >> s;
        solve(s, n);
    }
    return 0;
}