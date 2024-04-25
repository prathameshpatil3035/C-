#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = INT_MAX; // Represents infinity for weights

class Graph {
private:
    vector<vector<int>> adj_matrix;
    int num_vertices;

public:
    Graph(int num_vertices) : num_vertices(num_vertices) {
        // Initialize adjacency matrix with all INF (infinity) for weights
        adj_matrix.assign(num_vertices, vector<int>(num_vertices, INF));
    }

    void addEdge(int v1, int v2, int weight) {
        // For a weighted graph, set the weight of the edge
        adj_matrix[v1][v2] = weight;
        adj_matrix[v2][v1] = weight; // For undirected graph
    }

    bool isEdge(int v1, int v2) {
        return adj_matrix[v1][v2] != INF;
    }

    void removeEdge(int v1, int v2) {
        adj_matrix[v1][v2] = INF;
        adj_matrix[v2][v1] = INF; // For undirected graph
    }

    vector<int> getNeighbors(int vertex) {
        vector<int> neighbors;
        for (int i = 0; i < num_vertices; ++i) {
            if (adj_matrix[vertex][i] != INF) {
                neighbors.push_back(i);
            }
        }
        return neighbors;
    }

    bool isEmpty() {
        return num_vertices == 0;
    }

    int getNumVertices() {
        return num_vertices;
    }

    int getNumEdges() {
        int count = 0;
        for (int i = 0; i < num_vertices; ++i) {
            for (int j = i + 1; j < num_vertices; ++j) {
                if (adj_matrix[i][j] != INF) {
                    count++;
                }
            }
        }
        return count;
    }

    void DFSUtil(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        vector<int> neighbors = getNeighbors(vertex);
        for (int neighbor : neighbors) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    void DFS(int startVertex) {
        vector<bool> visited(num_vertices, false);
        DFSUtil(startVertex, visited);
        cout << endl;
    }

    void BFS(int startVertex) {
        vector<bool> visited(num_vertices, false);
        queue<int> q;
        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();
            cout << currentVertex << " ";

            vector<int> neighbors = getNeighbors(currentVertex);
            for (int neighbor : neighbors) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(4); // Create a graph with 4 vertices
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 3, 2);

    cout << "Number of vertices: " << g.getNumVertices() << endl;
    cout << "Number of edges: " << g.getNumEdges() << endl;

    cout << "Depth-First Search traversal starting from vertex 0: ";
    g.DFS(0);

    cout << "Breadth-First Search traversal starting from vertex 0: ";
    g.BFS(0);

    return 0;
}
