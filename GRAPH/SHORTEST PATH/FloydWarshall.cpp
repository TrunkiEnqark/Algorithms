#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int s, t, n, adj[N][N], dist[N][N], trace[N][N];

int main() {
    cin >> n >> s >> t;
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= n; ++j) {
            cin >> adj[i][j];
            dist[i][j] = (adj[i][j] == -1 ? 1e9 : adj[i][j]);
        }
    
    for (int i = 1; i <= n; ++i) dist[i][i] = 0; // distance(i -> i) = 0

    for (int u = 1; u <= n; ++u) 
        for (int v = 1; v <= n; ++v) {
            trace[u][v] = v;
        }

    for (int k = 1; k <= n; ++k) 
        for (int u = 1; u <= n; ++u) 
            for (int v = 1; v <= n; ++v) {
                if (dist[u][v] > dist[u][k] + dist[k][v]) {
                    dist[u][v] = dist[u][k] + dist[k][v];
                    trace[u][v] = trace[u][k];
                }
            }

    cout << dist[s][t] << endl;
    for (int i = s; i != t; i = trace[i][t]) 
        cout << i << ' ';
    cout << t;

    return 0;
}