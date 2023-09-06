#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, k;
char map[101][101]; 
bool visit[101][101];
int maxArea = -1;
int ddx[4] = {-1, 1, 0, 0};
int ddy[4] = {0, 0, -1, 1};
queue<pair<int, int> > q;

void bfs(int row, int col) {
    q.push(make_pair(row, col));
    int area = 1;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int dx = x + ddx[i];
            int dy = y + ddy[i];
            if(dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
            if(!visit[dx][dy] && map[dx][dy] == '#') {
                visit[dx][dy] = true;
                q.push(make_pair(dx, dy));
                area++;
            }
        }
    }
    maxArea = max(maxArea, area);
}

int main() {
    cin >> n >> m >> k;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            map[i][j] = '.';
        }
    }
    for (int i=0;i<k;i++) {
        int r, c;
        cin >> r >> c;
        map[r-1][c-1] = '#';
    }
    for (int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(map[i][j] == '#' && !visit[i][j]) {
                visit[i][j] = true;
                bfs(i, j);
            }
        }
    }
    cout << maxArea << "\n";
}