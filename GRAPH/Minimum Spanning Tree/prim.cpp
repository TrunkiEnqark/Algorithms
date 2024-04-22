#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;

int n, m;
int dist[N]; // distance
vector<pair<int, int>> adj[N];

int prim(int x) {
    fill(dist, dist + N, inf);
    dist[x] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, x});

    int MST = 0; // Minimum Spanning Tree
    while (!pq.empty()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (dist[u] != du) continue;

        MST += dist[u];
        dist[u] = -inf;

        for (auto it : adj[u]) {
            int v = it.second;
            int weight = it.first;
            if (dist[v] > weight) {
                pq.push({dist[v] = weight, v});
            }
        }
    }

    return MST;
}

int main() {
    cin >> n >> m;
    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }

    cout << prim(1);

    return 0;
}