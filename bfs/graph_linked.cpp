#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, edges, u, v, start;

    cout << "Enter number of vertices: ";
    cin >> n;
    if (n <= 0) {
        cout << "Number of vertices must be positive.\n";
        return 1;
    }

    vector<vector<int> > adj(n);
    vector<bool> visited(n, false);

    cout << "Enter number of undirected edges: ";
    cin >> edges;
    cout << "Enter each edge as u v (vertices 0 to " << n - 1 << "):\n";

    for (int i = 0; i < edges; ++i) {
        cin >> u >> v;
        if (u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Invalid vertices. Enter this edge again: ";
            --i;
            continue;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Enter starting vertex: ";
    cin >> start;
    if (start < 0 || start >= n) {
        cout << "Invalid starting vertex.\n";
        return 1;
    }

    cout << "Adjacency List:\n";
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        for (size_t j = 0; j < adj[i].size(); ++j)
            cout << adj[i][j] << ' ';
        cout << '\n';
    }

    cout << "BFS traversal: ";
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << ' ';

        for (size_t i = 0; i < adj[current].size(); ++i) {
            int neighbour = adj[current][i];
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    // Also traverse disconnected components.
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int current = q.front();
                q.pop();
                cout << current << ' ';
                for (size_t j = 0; j < adj[current].size(); ++j) {
                    int neighbour = adj[current][j];
                    if (!visited[neighbour]) {
                        visited[neighbour] = true;
                        q.push(neighbour);
                    }
                }
            }
        }
    }
    cout << '\n';
    return 0;
}
