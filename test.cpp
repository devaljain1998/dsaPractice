#include <bits/stdc++.h>
using namespace std;

int tabulationMethod(int n){
    vector <int> fib{1, 1};
    for(int i=2; i<n; i++){ fib.push_back( fib[i-1] + fib[i-2] ); }
    for(auto i: fib){ cout << i << " "; }
    cout << endl;
    return fib.back();
}

int main()
{
    string a = "Hello";
    string b = "World";
    if (a < b) {
        cout << "Smaller";
    }
    return 0;
}