#include <iostream>
#include <vector>
#include <queue>
#include <utility> // for pair
#include <algorithm> // add this header

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<pair<int, int>>> adjList; // Adjacency list with weights

public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    // Function to add an edge to the graph with weight
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back(make_pair(v, weight));
        adjList[v].push_back(make_pair(u, weight)); // For undirected graph
    }

    // Function to check if there is an edge between two vertices
    bool isEdge(int u, int v) {
        for (auto& p : adjList[u]) {
            if (p.first == v)
                return true;
        }
        return false;
    }

    // Function to remove an edge between two vertices
    void removeEdge(int u, int v) {
        adjList[u].erase(remove_if(adjList[u].begin(), adjList[u].end(), [&v](const pair<int, int>& p) { return p.first == v; }), adjList[u].end());
        adjList[v].erase(remove_if(adjList[v].begin(), adjList[v].end(), [&u](const pair<int, int>& p) { return p.first == u; }), adjList[v].end());
    }

    // Function to get the neighbors of a given vertex
    vector<pair<int, int>> getNeighbors(int vertex) {
        return adjList[vertex];
    }

    // Function to check if the graph is empty
    bool isEmpty() {
        return V == 0;
    }

    // Function to get the number of vertices in the graph
    int getNumVertices() {
        return V;
    }

    // Function to get the number of edges in the graph
    int getNumEdges() {
        int edges = 0;
        for (int i = 0; i < V; ++i) {
            edges += adjList[i].size();
        }
        return edges / 2; // Since each edge is counted twice in an undirected graph
    }

    // Depth-First Search traversal
    void DFSUtil(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (auto& neighbor : adjList[vertex]) {
            int v = neighbor.first;
            if (!visited[v])
                DFSUtil(v, visited);
        }
    }

    void DFS(int startVertex) {
        vector<bool> visited(V, false);
        cout << "DFS traversal starting from vertex " << startVertex << ": ";
        DFSUtil(startVertex, visited);
        cout << endl;
    }

    // Breadth-First Search traversal
    void BFS(int startVertex) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[startVertex] = true;
        q.push(startVertex);

        cout << "BFS traversal starting from vertex " << startVertex << ": ";

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";
            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    // Function to print the adjacency list representation of the graph
    void printAdjList() {
        for (int i = 0; i < V; ++i) {
            cout << "Adjacency list of vertex " << i << ": ";
            for (auto& p : adjList[i]) {
                cout << "(" << p.first << ", " << p.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph g(5);

    // Add weighted edges
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 5);
    g.addEdge(1, 2, 7);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 6);
    g.addEdge(2, 3, 9);
    g.addEdge(3, 4, 1);

    // Print adjacency list
    g.printAdjList();

    // Test additional methods
    cout << "isEdge(1, 2): " << (g.isEdge(1, 2) ? "true" : "false") << endl;
    cout << "isEdge(2, 4): " << (g.isEdge(2, 4) ? "true" : "false") << endl;

    g.removeEdge(1, 2);
    cout << "After removing edge (1, 2):" << endl;
    g.printAdjList();

    cout << "Neighbors of vertex 1: ";
    for (auto& neighbor : g.getNeighbors(1)) {
        cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
    }
    cout << endl;

    cout << "Graph is empty: " << (g.isEmpty() ? "true" : "false") << endl;
    cout << "Number of vertices: " << g.getNumVertices() << endl;
    cout << "Number of edges: " << g.getNumEdges() << endl;

    g.DFS(0);
    g.BFS(0);

    return 0;
}
