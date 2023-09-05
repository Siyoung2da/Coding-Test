#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int t, l;
int ddx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int ddy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int cnt[301][301];
bool visit[301][301];

void bfs(int row, int col, int destX, int destY) {
    queue<pair<int, int> > q;
    q.push(make_pair(row, col));
    visit[row][col] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x == destX && y == destY) {
            cout << cnt[x][y] <<"\n";
            break;
        }

        for(int i=0;i<8;i++) {
            int dx = x + ddx[i];
            int dy = y + ddy[i];
            if(dx < 0 || dx >= l || dy < 0 || dy >= l) continue;
            if(!visit[dx][dy]) {
                visit[dx][dy] = true;
                cnt[dx][dy] = cnt[x][y] + 1;
                q.push(make_pair(dx, dy));
            }
        }
    }
}

void init() {
    for (int i=0;i<301;i++) {
        for(int j=0;j<301;j++) {
            cnt[i][j] = 0;
            visit[i][j] = false;
        }
    }
}

int main() {
    cin >> t;
    for (int T=0;T<t;T++) {
        cin >> l;
        int nowX, nowY, goX, goY;
        cin >> nowX >> nowY >> goX >> goY;
        init();
        bfs(nowX, nowY, goX, goY);
    }
}