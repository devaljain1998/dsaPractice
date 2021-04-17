// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    private:
    map<int, int> getIndegreeMap(vector<int> adj[],const int& V) {
        map<int, int> indegree;
        
        for (int i = 0; i < V; i++) {
            for (const int neighbour: adj[i]) {
                indegree[neighbour]++;
            }
        }
        
        return indegree;
    }
    
    queue<int> buildQueue(map<int, int> indegree) {
        queue<int> q;
        
        for (auto indegreeSet: indegree) {
            const int node = indegreeSet.first;
            const int idegree = indegreeSet.second;
            
            if (idegree == 0) {
                q.push(node);        
            }
        }
        
        return q;
    }
    
	public:
	vector<int> topoSort(int V, vector<int> adj[]) {
	    map<int, int> indegree = getIndegreeMap(adj, V);
        queue<int> q = buildQueue(indegree);
        vector<int> sequence;
	    
	    while (!q.empty()) {
	        const int node = q.front();
	        
	        // Removing it from queue and adding it to sequence
	        q.pop();
	        sequence.push_back(node);
	        
	        for (auto neighbour: adj[node]) {
	            indegree[neighbour]--;
	            
	            // Push neighbour into the queue if it has 0 indegree
	            if (indegree[neighbour] == 0) {
	                q.push(neighbour);
	            }
	        }
	    }
	    
	    return sequence;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends