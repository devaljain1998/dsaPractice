// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    class Edge {
    public:
        int src;
        int dest;
        int weight;
        Edge(const int u, const int v, const int weight): src(u), dest(v), weight(weight) {}
    };
    
    class EdgeComparator
    {
    public:
        bool operator() (Edge a, Edge b)
        {
            return a.weight <= b.weight;
        }
    };
    
        unordered_set<int> visited;
        unordered_set<int> unvisited;
        unordered_map<int, vector<Edge> > graph;
        priority_queue<Edge, vector<Edge>, EdgeComparator> minHeap;
        
        // Methods:
        void initialize(int V, vector<vector<int>> adj[]) {
            
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < adj[i].size(); j++) {
                    auto v = adj[i][j];
                    
                    const int dest = v[0];
                    const int weight = v[1];
                    graph[i].push_back(Edge(i, dest, weight));
                
                    // Adding all the nodes to unvisited:
                    unvisited.insert(i);
                }
            }
            return;
        }
        
        int primsMST() {
            // Starting from 0 only in this problem as the graph is
            // perfectly given that it will be connected.
            // for (int i = 0; i < V; i++)
            int pathSum = 0;
            
            int src = 0;
            vector<Edge> neighbours = graph[src];
            for (auto neighbour: neighbours) {
                minHeap.push(neighbour);
            }
            visited.insert(src);
            unvisited.erase(src);
            
            while (unvisited.size() > 0) {
                const Edge edge = minHeap.top();
                minHeap.pop();
                const int node = edge.dest;
                
                // Checking if  the current node is not already visited to
                // to avoid cycles;
                if (visited.find(node) != visited.end())
                    continue;
                    
                pathSum += edge.weight;
                
                // Marking visited and unvisited
                visited.insert(node);
                unvisited.erase(node);
                
                // Adding the elements in heap:
                for (auto neighbourEdge: graph[node]) {
                    // only checking for the unvisited nodes
                    if (visited.find(neighbourEdge.dest) == visited.end()) {
                        minHeap.push(neighbourEdge);
                    }
                }
            }
            
            return pathSum;
        }
        
    	public:
    	// Function to construct and print MST for
        // a graph represented using adjacency
        // list representation, with V vertices.
        int spanningTree(int V, vector<vector<int>> adj[]) {
            initialize(V, adj);
            auto spanningTreeSum = primsMST();
            return spanningTreeSum;
        }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends