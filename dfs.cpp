//
// Created by donsimon on 12/19/24.
//
#include <iostream>
#include <vector>


class Graph {
public:
    int numVertices;
    std::vector<int> adjMatrix;

    Graph(int vertices) : numVertices(vertices), adjMatrix(vertices * vertices, 0) {}

    void addEdge(int u, int v, bool directed = false) {
        adjMatrix[u * numVertices + v] = 1;
        if (!directed) {
            adjMatrix[v * numVertices + u] = 1;
        }
    }

    void DFSUtil(int u, std::vector<bool> &visited) {
        visited[u] = true;
        std::cout<<u<<" ";

        for (int v = 0; v < numVertices; ++v) {
            if (adjMatrix[u * numVertices + v] && !visited[v]) {
                DFSUtil(v, visited);
            }
        }
    }

    void DFSAll() {
        std::vector<bool> visited(numVertices, false);
        for (int u = 0; u < numVertices; ++u) {
            if (!visited[u]) {
                DFSUtil(u, visited);
                std::cout<<std::endl;
            }
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(4,5);

    g.DFSAll();

    return 0;
}
