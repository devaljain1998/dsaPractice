// link: https://www.geeksforgeeks.org/given-sorted-dictionary-find-precedence-characters/
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    unordered_map<char, vector<char> > buildGraph(string dict[], int& N, int& K) {
        // Initialize graph:
        unordered_map<char, vector<char> > graph;
        for (int i = 0; i < K; i++) {
            char c = 'a' + i;
            graph[c];
        }
        
        // Build adjacency list:
        // loop through word and nextWord
        for (int i = 0; i < N - 1; i++) {
            const string word = dict[i];
            const string nextWord = dict[i + 1];
            
            // Compare both the words and reflect in the graph:
            const int minLen = min(word.size(), nextWord.size());
            
            for (int i = 0; i < minLen; i++) {
                const char currentChar = word[i];
                const char nextWordChar = nextWord[i];
                // if the chars are different then mark the order in the graph
                // and break the graph
                if (currentChar != nextWordChar) {
                    // check if the graph already contains the node
                    // otherwise add it to the graph
                    if (find(graph[currentChar].begin(), graph[currentChar].end(), nextWordChar) == graph[currentChar].end()) {
                        graph[currentChar].push_back(nextWordChar);
                        break;
                    }
                }
            }
            
        }
        
        return graph;
    }
    
    unordered_map<char, int> getIndegree(unordered_map<char, vector<char> >& graph) {
        unordered_map<char, int> indegree;
        
        for (auto ele:  graph) {
            auto node = ele.first;
            auto neighbours = ele.second;
            
            indegree[node];
            
            for (auto neighbour: neighbours) {
                indegree[neighbour]++;
            }
        }
        
        return indegree;
    }
    
    queue<char> getQueueFromIndegree(unordered_map<char, int>& indegree) {
        queue<char> q;
        
        for (auto ele: indegree) {
            auto node = ele.first;
            auto indegree = ele.second;
            
            if (indegree == 0)
                q.push(node);
        }
        
        return q;
    }
    
    string getSequence(
        unordered_map<char, vector<char> >& graph, 
        unordered_map<char, int>& indegree, queue<char>& q) {
            
            string order;
            
            while (!q.empty()) {
                const auto node = q.front();
                q.pop();
                order += node;
                
                for (auto neighbour: graph[node]) {
                    indegree[neighbour]--;
                    if (indegree[neighbour] == 0) {
                        q.push(neighbour);
                    }
                }
            }
            
            return order;
        }
    
    
    string topologicalSort(unordered_map<char, vector<char> >& graph) {
        auto indegree = getIndegree(graph);
        auto q = getQueueFromIndegree(indegree);
        auto order = getSequence(graph, indegree, q);
        return order;
    }
    
    public:
    string findOrder(string dict[], int N, int K) {
        auto graph = buildGraph(dict, N, K);
        auto order = topologicalSort(graph);
        return order;
    }
};



// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends