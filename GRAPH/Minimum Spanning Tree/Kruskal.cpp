#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct edge {
    int u, v, c;
};

struct DSU {
    int parent[N];

    int find_set(int u) {
        return parent[u] == 0 ? u : parent[u] = find_set(parent[u]);
    }

    bool union_sets(int u, int v) {
        u = find_set(u);
        v = find_set(v);

        if (u == v) {
            return false;
        }

        parent[v] = u;
        return true;
    }
} dsu;

int n, m; // So dinh, so canh
vector<edge> Edges; // Danh sach canh
vector<pair<int, int>> adj[N]; // {c, u}

int main() {
    cin >> n >> m;
    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;
        Edges.push_back({u, v, c});
    }

    sort(Edges.begin(), Edges.end(), [] (edge a, edge b) { return a.c < b.c; });

    int res = 0;
    for (auto it : Edges) {
        int u = it.u;
        int v = it.v;
        int c = it.c;
        if (dsu.union_sets(u, v)) {
            res += c;
            adj[u].push_back({c, v});
            adj[v].push_back({c, u});
        }
    }
    cout << res;

    return 0;
}