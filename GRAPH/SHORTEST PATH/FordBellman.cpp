#include <bits/stdc++.h>

using namespace std;

const int N = 1e5; //vertex
const int inf = 1e9;

struct edge {
    int u, v;
    long long w; // weight
};

int n, m;
int s;
int dist[N]; // Shortest path
int trace[N]; // trace v -> u 
vector<edge> Edges;

void FordBellman(int s) {
    fill(dist, dist + N, inf);
    fill(trace, trace + N, -1);
    dist[s] = 0;
    for (int T = 1; T < n; ++T) {
        for (edge e : Edges) {
            int u = e.u;
            int v = e.v;
            long long w = e.w;
            if (dist[u] != inf && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                trace[v] = u;
            }
        }
    }
    // check for negative-weight cycles
    for (int T = 0; T < n; ++T) {
        for (edge e : Edges) {
            int u = e.u;
            int v = e.v;
            long long w = e.w;
            if (dist[u] != inf && dist[v] > dist[u] + w) {
                dist[v] = -inf;
                trace[v] = u;
            }
        }
    }
} 

int main() {
    cin >> n >> m >> s;
    while (m--) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        Edges.push_back({u, v, w});
    }

    FordBellman(s);
    for (int i = 1; i <= n; ++i) cout << dist[i] << endl;

    return 0;
}