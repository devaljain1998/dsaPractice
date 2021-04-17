// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
    bool isInside(const vector<int> current, const int size) {
        return current[0] >= 1 && current[0] <= size && current[1] >= 1 && current[1] <= size; 
    }
    
    vector<int> move(const vector<int> current, const int i) {
        const vector<pair<int, int> > directions{
            {2, 1}, {2, -1},
            {-2, 1}, {-2, -1},
            {1, 2}, {-1, 2},
            {1, -2}, {-1, -2},
        };
        
        const pair<int, int> direction = directions[i];
        const vector<int, int> newPos{
            current[0] + direction.first, current[1] + direction.second};
        return newPos;
    }
public:
    /*
    Deductions:
        Moves by a knight:
            +2x +y, +2x -y
            -2x +y, -2x -y
            +2y +x, +2y -x
            -2y +x, -2y -x
    */
    int getMinSteps(vector<int>& current, vector<int>& target, int steps, const int size) {
        // BASE CONDITIONS:
        if (!isInside(current, size)) return INT_MAX;
        if (current == target) return steps;
        
        // Hypothesis:
        int minSteps = INT_MAX;
        
        for (int i = 1; i <= size; i++) {
            moveSteps = getMinSteps(move(current, i), target, steps + 1, size)
            minSteps = min(minSteps, moveSteps);            
        }
        
        return minSteps;
    }
    
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    int minimumSteps = getMinSteps(KnightPos, TargetPos, 1, N);
	    return minimumSteps;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends