#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjMatrix;

public:
    Graph(int vertices) {
        this->vertices = vertices;
        adjMatrix.resize(vertices, vector<int>(vertices, 0));
    }

    void addEdge(int v1, int v2) {
        if (v1 >= 0 && v1 < vertices && v2 >= 0 && v2 < vertices) {
            adjMatrix[v1][v2] = 1;
            adjMatrix[v2][v1] = 1; // For an undirected graph
        } else {
            cout << "Invalid vertex index" << endl;
        }
    }

    void display() {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// Example usage:
int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);

    cout << "Adjacency Matrix:" << endl;
    g.display();

    // Expected Output:
    // Adjacency Matrix:
    // 0 1 1 0
    // 1 0 0 1
    // 1 0 0 0
    // 0 1 0 0

    return 0;
}
