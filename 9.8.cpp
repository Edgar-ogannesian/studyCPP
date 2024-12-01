#include <iostream>
#include <vector>
#include <queue>
#include <limits>

void dijkstra(int src,const std::vector<std::vector<std::pair<int,int>>>& graph) {
    int n=graph.size();
    std::vector<int> dist(n,std::numeric_limits<int>::max());
    dist[src]=0;
    std::priority_queue<std::pair<int, int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> pq;
    pq.push({0,src});

    while (!pq.empty()) {
        int u=pq.top().second;
        pq.pop();
        for (const auto& neighbor:graph[u]) {
            int v=neighbor.first;
            int weight=neighbor.second;
            if (dist[u]+weight < dist[v]) {
                dist[v]=dist[u]+weight;
                pq.push({dist[v],v});
            }
        }
    }
    for (int i=0; i<n;++i) {
        std::cout <<src<<i<<dist[i]<<std::endl;
    }
}

int main() {
    std::vector<std::vector<std::pair<int,int>>> graph = {
        {{1, 4}, {2, 1}},
        {{3, 1}},
        {{1, 2}, {3, 5}},
        {}
    };
    dijkstra(0, graph);
    return 0;
}