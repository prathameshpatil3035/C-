#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph {
private:
    vector<vector<int>> adj_matrix;
    int num_vertices;
    int num_edges;

public:
    Graph(int num_vertices) : num_vertices(num_vertices), num_edges(0) {
        // Initialize adjacency matrix with all 0s
        adj_matrix.assign(num_vertices, vector<int>(num_vertices, 0));
    }

    void addEdge(int v1, int v2) {
        // For an unweighted graph, set the corresponding cells to 1
        adj_matrix[v1][v2] = 1;
        adj_matrix[v2][v1] = 1; // For undirected graph
        ++num_edges;
    }

    bool isEdge(int v1, int v2) {
        return adj_matrix[v1][v2] == 1;
    }

    void removeEdge(int v1, int v2) {
        adj_matrix[v1][v2] = 0;
        adj_matrix[v2][v1] = 0; // For undirected graph
        --num_edges;
    }

    vector<int> getNeighbors(int vertex) {
        vector<int> neighbors;
        for (int i = 0; i < num_vertices; ++i) {
            if (adj_matrix[vertex][i] == 1) {
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
        return num_edges;
    }

    void DFS(int start_vertex) {
        vector<bool> visited(num_vertices, false);
        stack<int> stack;
        stack.push(start_vertex);

        while (!stack.empty()) {
            int current_vertex = stack.top();
            stack.pop();

            if (!visited[current_vertex]) {
                cout << current_vertex << " ";
                visited[current_vertex] = true;

                vector<int> neighbors = getNeighbors(current_vertex);
                for (int neighbor : neighbors) {
                    if (!visited[neighbor]) {
                        stack.push(neighbor);
                    }
                }
            }
        }
    }

    void BFS(int start_vertex) {
        vector<bool> visited(num_vertices, false);
        queue<int> queue;
        visited[start_vertex] = true;
        queue.push(start_vertex);

        while (!queue.empty()) {
            int current_vertex = queue.front();
            queue.pop();
            cout << current_vertex << " ";

            vector<int> neighbors = getNeighbors(current_vertex);
            for (int neighbor : neighbors) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.push(neighbor);
                }
            }
        }
    }

    void printGraph() {
        for (int i = 0; i < num_vertices; ++i) {
            cout << "Adjacent to vertex " << i << ": ";
            for (int j = 0; j < num_vertices; ++j) {
                if (adj_matrix[i][j] == 1) {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(6); // Create a graph with 6 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    cout << "Graph representation:" << endl;
    g.printGraph();

    cout << "\nIs there an edge between vertices 1 and 4? ";
    cout << (g.isEdge(1, 4) ? "Yes" : "No") << endl;

    cout << "\nRemoving edge between vertices 1 and 4..." << endl;
    g.removeEdge(1, 4);

    cout << "\nIs there an edge between vertices 1 and 4 now? ";
    cout << (g.isEdge(1, 4) ? "Yes" : "No") << endl;

    cout << "\nNeighbors of vertex 1: ";
    vector<int> neighbors = g.getNeighbors(1);
    for (int neighbor : neighbors) {
        cout << neighbor << " ";
    }
    cout << endl;

    cout << "\nPerforming DFS traversal starting from vertex 0: ";
    g.DFS(0);
    cout << endl;

    cout << "\nPerforming BFS traversal starting from vertex 0: ";
    g.BFS(0);
    cout << endl;

    return 0;
}
