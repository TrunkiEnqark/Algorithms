#include <bits/stdc++.h>

using namespace std;

const int N = 1e5; // Vertex

int n, m; // Vertex, Edges
vector<int> adj[N]; // Adjacency list
int vst[N]; // Visited

void dfs(int u) {
    cout << u << ' ';
    for (int v : adj[u]) 
        if (vst[v]) {
            vst[v] = false;
            dfs(v);
        }
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
        if (vst[i]) {
            vst[i] = false;
            dfs(i);
            cout << '\n';
        }
    return 0;
}