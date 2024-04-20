#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

class DisjointSet {
private:
    int sz[N], parent[N];
public:
    void make_set(int u) {
        parent[u] = u;
        sz[u] = 1;
    }

    int find_set(int u) {
        return u == parent[u] ? u : parent[u] = find_set(parent[u]);
    }

    void union_sets(int u, int v) {
        u = find_set(u);
        v = find_set(v);
        if (u != v) {
            if (sz[u] < sz[v]) swap(u, v);
            parent[v] = u;
            sz[u] += sz[v];
        }
    }

    bool is_unioned(int u, int v) {
        return find_set(u) == find_set(v);
    }
} dsu;

int main() {
    for (int i = 1; i <= 10; ++i) dsu.make_set(i);
    dsu.union_sets(1, 3);
    cout << dsu.is_unioned(1, 3);

    return 0;
}