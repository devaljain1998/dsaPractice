/*
url: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
*/
class Solution {
public:
	bool isCycle(int V, vector<int>adj[]){
	    // A Map for parent:
	    unordered_map<int, int> parent;
	    set<int> visited;
	    
	    // Using BFS:
	    queue<int> q;
	    // Pushing 0 in the queue
	    // and setting it's parent to NULL.
	    q.push(0);
	    parent[0] = NULL;
	    
	    while (!q.empty()) {
	        const int node = q.front();
	        q.pop();
	        
	        if (visited.find(node) != visited.end()) {
	            return true;
	        } else {
	            visited.insert(node);
	        }
	        
	        // Check for each neighbour.
	        // if the neighbour is visited and the neighbour is not
	        // the parent of the current node then cycle exists.
	        for (const int neighbour: adj[node]) {
	            // cycle found
	            if (visited.find(neighbour) != visited.end() && parent[node] != neighbour) {
	                return true;
	            } else {
	                parent[neighbour] = node;
	                q.push(neighbour);
	            }
	        }
	        
	    }
	    
	    return false;
	}
};