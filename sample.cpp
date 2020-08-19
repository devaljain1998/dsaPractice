#include <bits/stdc++.h> 
using namespace std;

// between 30 and 3 I want 3 > 30
// 303 < 330

struct StringComparator { 
    bool operator()(string const& s1, string const& s2) 
    { 
        // return "true" if "p1" is ordered  
        // before "p2", for example: 
        //return p1.height < p2.height; 
        
        string s1s2 = s1 + s2;
        string s2s1 = s2 + s1;
        
        return s1s2 < s2s1;
    } 
};

class Solution{
    public:
    string largestNumber(const vector<int> &A);
};

string Solution::largestNumber(const vector<int> &A) {
    vector<string> numberStrings(A.size());
    
    for (int i = 0; i < A.size(); i++) {
        numberStrings[i] = to_string(A[i]);
    }
    
    sort(numberStrings.begin(), numberStrings.end(), greater<string>());
    
    
    //, StringComparator
    try
    {
        priority_queue<string, vector<string>, StringComparator> HeapOfStrings; //(numberStrings.begin(), numberStrings.end())
        
        // cout << HeapOfStrings.size() << endl;
        
        for (auto s: numberStrings) {
            HeapOfStrings.push(s);
            // cout << HeapOfStrings.size();
        }

        string largestNumber;
        
        while (HeapOfStrings.empty()) {
            // cout << HeapOfStrings.top() << " ";
            largestNumber += HeapOfStrings.top();
            // cout << largestNumber << endl;
            HeapOfStrings.pop();
        }
        
        return largestNumber;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(...) {
        cout << "Exception occured.";
    }
    
    
    // cout << HeapOfStrings.empty() << endl;
    
}



int main() {
    vector<int> A{89, 8};
    cout << Solution().largestNumber(A);
    return 0;
}