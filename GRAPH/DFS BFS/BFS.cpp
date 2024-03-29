#include <bits/stdc++.h>

using namespace std;

const int N = 1e5; // Vertex

int n, m; // Vertex, Edges
vector<int> adj[N]; // Adjacency list
int vst[N]; // Visited

void bfs(int u) {
    vst[u] = false;
    queue<int> qu;
    qu.push(u);
    // BFS
    while (!qu.empty()) {
        int x = qu.front();
        cout << x << ' ';
        qu.pop();
        for (int y : adj[x])
            if (vst[y]) {
                vst[y] = false;
                qu.push(y);
            }
    }
    cout << '\n';
}

int main() {
    cin >> n >> m;
    for (int _ = m; _--;) {
        int u, v;
        cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(vst, true, sizeof vst);
    for (int i = 1; i <= n; ++i) 
        if (vst[i]) bfs(i);

    return 0;
}