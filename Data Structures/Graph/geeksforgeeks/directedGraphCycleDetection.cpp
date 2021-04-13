class Solution {
public:
    /*
    PROCEDURE:
        Approach: Traverse the graph using DFS and if a node found which is already
        in recursiveStack then the we figure out the graph is cyclic (
            through codingsimplified video on youtube.
        )
        
        1. Maintain a visited and recursiveStack vector of bool
        2. Traverse the array through dfs
        3. for node in nodes => 
            dfs(node)
            if dfs(node) return true else continue
        4. return false
        
        dfs(int node)
            if recursiveStack[node] == true: return true
            if visited[node]: return false
        
            visited[node] = true
            recursiveStack[node] = true
            
            for (auto neighbour: adj[node) {
                bool cycleFound = dfs(neighbour)
                return true if cycleFound else continue
            }
            
            recursiveStack[node] = false
    */
    
    bool dfs(const int node, vector<bool>& visited, vector<bool>& recursiveStack, vector<int> adj[]) {
        if (recursiveStack[node] == true) {
            return true;
        }
        if (visited[node]) {
            return false;
        }

        visited[node] = true;
        recursiveStack[node] = true;

        for (auto neighbour: adj[node]) {
            bool cycleFound = dfs(neighbour, visited, recursiveStack, adj);
            if (cycleFound) 
                return true;
        }

        recursiveStack[node] = false;
        return false;
    }
    
	bool isCyclic(int V, vector<int> adj[]) {
        // 1. Maintain a visited and recursiveStack vector of bool
        vector<bool> visited(V, false);
        vector<bool> recursiveStack(V, false);
        
        // 2. Traverse the array through dfs
        // 3. for node in nodes => 
        //     dfs(node)
        //     if dfs(node) return true else continue
        for (int i = 0; i < V; i++) {
            const int node = i;
            
            if (dfs(node, visited, recursiveStack, adj)) return true;
        }
        // 4. return false
	    return false;
	}
};