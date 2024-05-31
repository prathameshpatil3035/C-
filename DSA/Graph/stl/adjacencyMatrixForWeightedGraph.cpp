#include <iostream>
#include <vector>
#include <iomanip> // For setting the output format

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjMatrix;

public:
    Graph(int vertices) {
        this->vertices = vertices;
        adjMatrix.resize(vertices, vector<int>(vertices, INT_MAX));
        // Set diagonal to 0, as the distance from a vertex to itself is 0
        for (int i = 0; i < vertices; ++i) {
            adjMatrix[i][i] = 0;
        }
    }

    void addEdge(int v1, int v2, int weight) {
        if (v1 >= 0 && v1 < vertices && v2 >= 0 && v2 < vertices) {
            adjMatrix[v1][v2] = weight;
            adjMatrix[v2][v1] = weight; // For an undirected graph
        } else {
            cout << "Invalid vertex index" << endl;
        }
    }

    void display() {
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                if (adjMatrix[i][j] == INT_MAX)
                    cout << setw(8) << "∞";
                else
                    cout << setw(8) << adjMatrix[i][j];
            }
            cout << endl;
        }
    }
};

// Example usage:
int main() {
    Graph g(4);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 8);

    cout << "Adjacency Matrix:" << endl;
    g.display();

    // Expected Output:
    // Adjacency Matrix:
    // 0        2        4        ∞
    // 2        0        ∞        6
    // 4        ∞        0        8
    // ∞        6        8        0

    return 0;
}
