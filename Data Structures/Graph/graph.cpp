#include <bits/stdc++.h>

class Graph {
private:
    unordered_map<int, vector<int>> graph;
public:
    // Node Methods:
    bool addNode(int node);
    bool nodeExists(int node);
    bool getNode(int node);
    bool deleteNode(int node);

    // Edge Methods:
    bool addEdge(int source, int dest);
    bool edgeExists(int source, int dest);
    vector<int> getEdges(int source);

}