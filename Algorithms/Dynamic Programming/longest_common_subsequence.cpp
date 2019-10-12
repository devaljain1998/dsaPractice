#include<bits/stdc++.h>
using namespace std;

/*
link: https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
*/

void dislpayVector(const vector <vector<int> > &v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int lengthofLongestCommonSubsequence(string s1, string s2){
    //int lengthOfSubsequence[s1.length()+1][s2.length()+1] = {0} ;
    vector < vector<int> > lengthOfSubsequence(s1.length()+1, vector <int> (s2.length()+1, 0));

    // //Filling first row and first column to 0
    // memset(lengthOfSubsequence[0], 0, sizeof(lengthOfSubsequence[0])); //Row
    // for(int i=0; i<s2.length()+1; i++){
    //     lengthOfSubsequence[i][0] = 0;
    // }

    dislpayVector(lengthOfSubsequence);

    for(int i=1; i<s2.length()+1; i++){
        for(int j=1; j<s1.length()+1; j++){
            lengthOfSubsequence[i][j] = (s1[j-1]==s2[i-1]) 
                                        ? lengthOfSubsequence[i-1][j-1] + 1 
                                        : max(lengthOfSubsequence[i-1][j], lengthOfSubsequence[i][j-1]) ;
        }
    }
    cout << "\n\n----<<<<>>>>------\n\n";
    dislpayVector(lengthOfSubsequence);

    return lengthOfSubsequence[s1.length()][s2.length()];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s1, s2;
        int s1_length, s2_length;
        cin >> s1_length >> s2_length;
        cin >> s1 >> s2;
        cout << lengthofLongestCommonSubsequence(s1, s2) << endl;
    }
    return 0;
}