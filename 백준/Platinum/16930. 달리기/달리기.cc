#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, k;
char map[1001][1001];
int visit[1001][1001];
int ddx[4] = {-1, 1, 0, 0};
int ddy[4] = {0, 0, -1, 1};
queue<pair<int, int> > q;

void bfs(int x1, int y1, int x2, int y2) {
    bool flag = false;
    visit[x1][y1] = 0;
    q.push(make_pair(x1, y1));

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        // cout << x << ", " << y << " time : " << visit[x][y] << "\n";
        q.pop();
        if(x == x2 && y == y2) {
            flag = true;
            cout << visit[x][y] << "\n";
            break;
        }
        for(int i=0;i<4;i++) {
            for (int j = 1;j<=k;j++) {
                int dx = x + ddx[i] * j;
                int dy = y + ddy[i] * j;
                if(dx <= 0 || dy <= 0) continue;
                if(dx > n || dy > m || map[dx][dy] == '#') break;
                if(visit[dx][dy] > 0) {
                    if(visit[dx][dy] >= visit[x][y] + 1)
                        visit[dx][dy] = visit[x][y] + 1;
                    if(visit[dx][dy] < visit[x][y] + 1) break;
                }
                if(visit[dx][dy] == -1 && map[dx][dy] == '.') {
                    visit[dx][dy] = visit[x][y] + 1;
                    q.push(make_pair(dx, dy));
                }
            }
        }
    }

    if(!flag) cout << "-1\n";
}

int main() {
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            char c;
            cin >> c;
            map[i][j] = c;
        }
    }
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            visit[i][j] = -1;
        }
    }
    bfs(x1, y1, x2, y2);
    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=m;j++) {
    //         cout << visit[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}