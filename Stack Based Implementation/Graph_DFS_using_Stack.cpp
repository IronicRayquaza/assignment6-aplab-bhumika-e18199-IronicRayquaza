#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

class Graph {
private:
    unordered_map<int, vector<int>> adj;

public:
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int start) {
        stack<int> s;
        unordered_map<int, bool> visited;
        s.push(start);

        while (!s.empty()) {
            int node = s.top();
            s.pop();

            if (!visited[node]) {
                cout << node << " ";
                visited[node] = true;
            }

            for (auto neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
};

int main() {
    Graph g;
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 6);
    g.addEdge(3, 7);

    cout << "DFS Traversal: ";
    g.DFS(1);

    return 0;
}
