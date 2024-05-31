#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

class Graph {
private:
    int vertices;
    map<int, list<int>> adjList;

public:
    Graph(int vertices) {
        this->vertices = vertices;
        for (int i = 0; i < vertices; ++i) {
            adjList[i] = list<int>();
        }
    }

    void addEdge(int v1, int v2) {
        // Adding an edge between vertex v1 and v2
        if (v1 >= 0 && v1 < vertices && v2 >= 0 && v2 < vertices) {
            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1); // For undirected graph
        } else {
            cout << "Invalid vertex index" << endl;
        }
    }

    void display() {
        for (auto const& pair : adjList) {
            cout << pair.first << " -> ";
            for (int vertex : pair.second) {
                cout << vertex << " ";
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

    cout << "Adjacency List:" << endl;
    g.display();

    // Expected Output:
    // Adjacency List:
    // 0 -> 1 2
    // 1 -> 0 3
    // 2 -> 0
    // 3 -> 1

    return 0;
}
