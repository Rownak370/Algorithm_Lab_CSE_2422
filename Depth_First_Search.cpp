#include<bits/stdc++.h>
using namespace std;
void DFS(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, graph, visited);
        }
    }
}
int main() {
    int n, edges;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> edges;

    vector<vector<int>> graph(n);

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);   
    }
    vector<bool> visited(n, false);

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    cout << "DFS Traversal: ";
    DFS(start, graph, visited);

    return 0;
}

