#include <bits/stdc++.h>
using namespace std;

// Example: [1, 3, 5, 6], target=9
//                 Output: sum=3+6=9 → answer=[1,3]
//                 [0, -1, 3, -3, 1], target=-2
 
// Naive Soltions: O(n2)
// Two Pointer : O(nlogn) while(i < j)
// Hashing : sum, k => sum -k available then we have the solution.

pair<int, int> twoPointers(vector<int> &v, int &target) {
    // Sorting the array
    sort(v.begin(), v.end());

    //Init
    int left = 0, right = v.size() - 1;

    while (left < right) {
        int sum = v[left] + v[right];

        //Conditions:
        if (sum == target) return make_pair(left, right);
        if (sum < target) left++;
        else right--;
    }

    return make_pair(-1, -1);
}


int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int target;
    cin >> target;

    auto ans = twoPointers(v, target);

    if (ans.first == -1 && ans.second == -1)
        cout << "No sol" << endl;
    else
        cout << "Answers are at indexes: (" << ans.first << ", " << ans.second << ") " <<  endl;
    return 0;
}