#include <iostream>
#include <vector>

void warshall(std::vector<std::vector<int>>& graph) {
    int n = graph.size();

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }
}

void printTransitiveClosure(const std::vector<std::vector<int>>& tc) {
    int n = tc.size();
    std::cout << "Transitive Closure Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << tc[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    int n; 
    std::cout << "Enter the number of vertices: ";
    std::cin >> n;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n));

    std::cout << "Enter the adjacency matrix (0 for no edge, 1 for an edge):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> graph[i][j];
        }
    }

    warshall(graph);
    printTransitiveClosure(graph);

    return 0;
}