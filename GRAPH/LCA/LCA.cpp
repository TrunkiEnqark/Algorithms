#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const int LOG = 21;

int n, q, up[N][LOG], height[N];
int min_dist[N][LOG], max_dist[N][LOG];
vector<pair<int, int> > g[N];

void dfs(int u) {
    for (auto i : g[u]) {
        int v = i.second;
        int uv = i.first;
        if (v == up[u][0]) continue;
        height[v] = height[u] + 1;

        up[v][0] = u;
        min_dist[v][0] = uv;
        max_dist[v][0] = uv;
        for (int j = 1; j < LOG; ++j) {
            min_dist[v][j] = min(min_dist[v][j - 1], min_dist[up[v][j - 1]][j - 1]);
            max_dist[v][j] = max(max_dist[v][j - 1], max_dist[up[v][j - 1]][j - 1]);
            up[v][j] = up[up[v][j - 1]][j - 1];
        }

        dfs(v);
    }
}

pair<int, int> lca(int u, int v) {
    pair<int, int> res = {1e9, -1e9};
    if (height[u] < height[v]) swap(u, v);
    int diff = height[u] - height[v];
    for (int i = 0; (1 << i) <= diff; ++i) 
        if (diff & (1 << i)) {
            // cout << res.first << ' ' << res.second << endl;
            res.first = min(res.first, min_dist[u][i]);
            res.second = max(res.second, max_dist[u][i]);
            u = up[u][i];
        }

    if (u == v) return res;

    int k = __lg(height[u]);

    for (int i = k; i >= 0; --i) {
        if (up[u][i] != up[v][i]) { 
            res.first = min({res.first, min_dist[u][i], min_dist[v][i]});
            res.second = max({res.second, max_dist[u][i], max_dist[v][i]});

            u = up[u][i];
            v = up[v][i];
        }
    }
    res.first = min({res.first, min_dist[u][0], min_dist[v][0]});
    res.second = max({res.second, max_dist[u][0], max_dist[v][0]});
    return res;
}

int main() {
    cin >> n;
    for (int _ = 1; _ < n; ++_) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({c, v});
        g[v].push_back({c, u});
    }
    dfs(1);

    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        auto res = lca(u, v);
        cout << res.first << ' ' << res.second << '\n';
    }

    return 0;
}