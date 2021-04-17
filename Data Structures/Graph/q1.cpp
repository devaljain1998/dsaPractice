/*
Questions are taken from: 
https://onedrive.live.com/?authkey=%21AHSXkB1hO0WsA3Q&cid=842AECBB531CCEA4&id=842AECBB531CCEA4%218988&parId=842AECBB531CCEA4%218987&o=OneUp

Question:
Create a class Graph and implement the following functions/methods in that class:
-addNewEdge(source, destination, distance)
-printAdjacencyList()
-bfsTraversal()
[Follow here: https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/]
-dfsTraversal()[Follow here: https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/]
*/

#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    unordered_map<int, unordered_map<int, int>> graph;
public:
    void addNewEdge(int source, int destination, int distance) {
        graph[source][destination] = distance;
        graph[destination][source] = distance;
    }

    void printGraph() {
        // Printing Edges:
        for (auto edgeSet: graph) {
            const auto node = edgeSet.first;
            const auto edges = edgeSet.second;

            // Printing:
            int edgeCount = 0;
            cout << node << ": ";
            for (auto target: edges) {
                cout << edge;
                if (edgeCount < edge.size() - 1)
                    cout << ", ";
                else
                    cout << endl;
            }
        }
    }

    void bfsTraversal(int source) {
        queue<int> q;
        unordered_set<int> visitedNodes;

        // Adding the source node to queue and marking it as visited:
        q.push(source); visitedNodes.insert(source);

        while (! q.empty()) {
            const int currentNode = q.front();
            q.pop();
            visitedNodes.insert(currentNode);
            // Fetch all the nodes of the of the current node:
            vector<int> neighbourNodes;
            for (const auto neighbourNode: graph[currentNode]) {
                const auto neighbour = neighbourNode.first;
                neighbourNodes.push_back(neighbour);

                // Push this node into queue if already not visited:
                if (visitedNodes.find(neighbour) != visitedNodes.end()) {
                    q.push(neighbour);
                }
            }
            cout << currentNode;
        }
        cout << endl;
    }
}