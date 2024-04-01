#include <bits/stdc++.h>

#define ii pair<int, int>
#define fi first 
#define se second

using namespace std;

const int inf = 1e9;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int robot_x, robot_y;
int goal_x, goal_y;
int n, m, a[100][100], dist[100][100];
bool vst[100][100];

void init() {
    for (int i = 0; i < 100; ++i)
        for (int j = 0; j < 100; ++j) {
            dist[i][j] = inf;
            vst[i][j] = true;
        }
}

void bfs(int start_x, int start_y) {
    queue<ii> qu;
    qu.push({start_x, start_y});
    dist[start_x][start_y] = 0;
    vst[start_x][start_y] = false;
    
    while (!qu.empty()) {
        int i = qu.front().fi;
        int j = qu.front().se;
        qu.pop();

        for (int k = 0; k < 4; ++k) {
            int u = i + dx[k];
            int v = j + dy[k];
            
            // 1 <= u <= n and 1 <= v <= m
            if (1 <= u && u <= n && 1 <= v && v <= m) {
                if (vst[u][v] && a[u][v] == 1 && dist[u][v] > dist[i][j] + 1) {
                    vst[u][v] = false;
                    dist[u][v] = dist[i][j] + 1;
                    qu.push({u, v});
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    cin >> robot_x >> robot_y >> goal_x >> goal_y;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) cin >> a[i][j];
    init();
    bfs(robot_x, robot_y);
    cout << dist[goal_x][goal_y];
}