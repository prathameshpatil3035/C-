#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <sstream>

using namespace std;

class Graph {
private:
    int vertices;
    map<int, list<pair<int, int>>> adjList;

public:
    Graph(int vertices) {
        this->vertices = vertices;
        for (int i = 0; i < vertices; ++i) {
            adjList[i] = list<pair<int, int>>();
        }
    }

    void addEdge(int v1, int v2, int weight) {
        // Adding an edge between vertex v1 and v2 with weight
        if (v1 >= 0 && v1 < vertices && v2 >= 0 && v2 < vertices) {
            adjList[v1].push_back(make_pair(v2, weight));
            adjList[v2].push_back(make_pair(v1, weight)); // For undirected graph
        } else {
            cout << "Invalid vertex index" << endl;
        }
    }

    void display() {
        for (auto const& pair : adjList) {
            cout << pair.first << " -> ";
            for (auto const& neighbour : pair.second) {
                cout << neighbour.first << " (" << neighbour.second << ") ";
            }
            cout << endl;
        }
    }
};

// Example usage:
int main() {
    Graph g(4);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 1);

    cout << "Adjacency List:" << endl;
    g.display();

    // Expected Output:
    // Adjacency List:
    // 0 -> 1 (2) 2 (3)
    // 1 -> 0 (2) 3 (1)
    // 2 -> 0 (3)
    // 3 -> 1 (1)

    return 0;
}
