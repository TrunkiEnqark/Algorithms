#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m, s, t;
int dist[N]; // distance
int trace[N];
vector<pair<int, int>> adj[N];

void dijkstra(int x) {
    fill(dist, dist + N, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, x});
    dist[x] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (dist[u] != du) continue;

        for (auto it : adj[u]) {
            int v = it.second;
            int uv = it.first;
            if (dist[v] > du + uv) {
                trace[v] = u;
                pq.push({dist[v] = du + uv, v});
            }
        }
    }
}

int main() {
    cin >> n >> m >> s >> t;
    for (int _ = m; _--;) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }
    dijkstra(s);
    cout << dist[t] << endl;
    for (int i = t; i > 0; i = trace[i]) 
        cout << i << ' ';

    return 0;
}