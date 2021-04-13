#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    map<int, vector<int> > edges;

public:
    // constructor:

    // utils:
    void display();
    vector<int> getNeighbours(const int src);

    // add remove
    bool addEdge(const int src, const int dest);
    bool removeEdge(const int src, const int dest);

    // traversal
    void dfs(int src = NULL);
    void bfs(int src = NULL);

    // algos:
    // shortest path
    vector<int> djikistra(const int src, const int dest);
    // cycle:
    bool isCyclic();
    vector<int> getCycle();
};

void Graph::display() {
    cout << "Graph:\n";
    for (const auto edgeSet: edges) {
        const int vertex = edgeSet.first;
        const vector<int> vertexEdges = edgeSet.second;
        cout << vertex << ": ";
        for (auto v: vertexEdges) {
            cout << v << " ";
        }
        cout << endl;
    }
}

vector<int> Graph::getNeighbours(const int src) {
    // Check the src exists
    if (edges.find(src) == edges.end()) {
        cout << src << ",  " << dest << " does not exist" << endl;
        return vector<int>{};
    }

    return edges[src];
}

bool Graph::addEdge(const int src, const int dest) {
    // Check if the edge already exists:
    if (find(edges[src].begin(), edges[src].end(), dest) == edges[src].end()) {
        cout << src << ",  " << dest << " already exists." << endl;
        return false;
    }

    // Add edge:
    edges[src].push_back(dest);

    return true;
}

bool Graph::removeEdge(const int src, const int dest) {
    // Check if the edge already exists:
    if (find(edges[src].begin(), edges[src].end(), dest) != edges[src].end()) {
        cout << src << ",  " << dest << " does not exist" << endl;
        return false;
    }

    // Remove edge:
    edges[src].erase(remove(edges[src].begin(), edges[src].end(), dest), edges[src].end());
    return true;
}

//Traversal:
void Graph::bfs(int src = NULL) {
    // Check if src exists:
    if (src != NULL && edges.find(src) == edges.end()) {
        string exc = src + " is not found in graph edges.";
        throw exception(exc);
    }
    // If src is null then set it to the first vertice:
    if (src == NULL) {
        src = *(edges.begin()).first;
    }

    set<int> visited;
    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        const int vertice = q.top();
        q.pop();
        visited.insert(vertice);

        for (auto v: edges[vertices]) {
            if (visited.find(v) != visited.end()) {
                q.push(v);
            }
        }
    }

    return;
}

void Graph::dfs(int src = NULL) {
    // Check if src exists:
    if (src != NULL && edges.find(src) == edges.end()) {
        string exc = src + " is not found in graph edges.";
        throw exception(exc);
    }
    // If src is null then set it to the first vertice:
    if (src == NULL) {
        src = *(edges.begin()).first;
    }

    set<int> visited;
    stack<int> s;
    s.push(src);

    while (!s.empty()) {
        const int vertice = q.top();
        s.pop();
        visited.insert(vertice);

        for (auto v: edges[vertices]) {
            if (visited.find(v) != visited.end()) {
                s.push(v);
            }
        }
    }

    return;
}

int main() {

    return 0;
}