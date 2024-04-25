#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adjList; // Adjacency list

public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    // Function to check if there is an edge between two vertices
    bool isEdge(int u, int v) {
        for (int neighbor : adjList[u]) {
            if (neighbor == v) {
                return true;
            }
        }
        return false;
    }

    // Function to remove an edge between two vertices
    void removeEdge(int u, int v) {
        adjList[u].erase(remove(adjList[u].begin(), adjList[u].end(), v), adjList[u].end());
        adjList[v].erase(remove(adjList[v].begin(), adjList[v].end(), u), adjList[v].end());
    }

    // Function to get the neighbors of a given vertex
    vector<int> getNeighbors(int v) {
        return adjList[v];
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
        int count = 0;
        for (int i = 0; i < V; ++i) {
            count += adjList[i].size();
        }
        return count / 2; // For undirected graph
    }

    // Function to perform Depth-First Search traversal
    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> s;
        s.push(start);

        while (!s.empty()) {
            int current = s.top();
            s.pop();

            if (!visited[current]) {
                cout << current << " ";
                visited[current] = true;

                // Push unvisited neighbors onto the stack
                for (int neighbor : adjList[current]) {
                    if (!visited[neighbor]) {
                        s.push(neighbor);
                    }
                }
            }
        }
        cout << endl;
    }

    // Function to perform Breadth-First Search traversal
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            // Enqueue unvisited neighbors
            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        cout << endl;
    }

    // Function to print the adjacency list representation of the graph
    void printAdjList() {
        for (int i = 0; i < V; ++i) {
            cout << "Adjacency list of vertex " << i << ": ";
            for (int v : adjList[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph g(5);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Test methods
    cout << "Is edge between 1 and 3? " << (g.isEdge(1, 3) ? "Yes" : "No") << endl;
    cout << "Is edge between 0 and 2? " << (g.isEdge(0, 2) ? "Yes" : "No") << endl;

    cout << "Removing edge between 1 and 4..." << endl;
    g.removeEdge(1, 4);
    g.printAdjList();

    cout << "Neighbors of vertex 1: ";
    vector<int> neighbors = g.getNeighbors(1);
    for (int v : neighbors) {
        cout << v << " ";
    }
    cout << endl;

    cout << "Is the graph empty? " << (g.isEmpty() ? "Yes" : "No") << endl;
    cout << "Number of vertices: " << g.getNumVertices() << endl;
    cout << "Number of edges: " << g.getNumEdges() << endl;

    cout << "DFS traversal starting from vertex 0: ";
    g.DFS(0);

    cout << "BFS traversal starting from vertex 0: ";
    g.BFS(0);

    return 0;
}
