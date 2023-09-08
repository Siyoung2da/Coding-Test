#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int map[51][51];
bool visit[51][51];
int maxArea;
int ddx[8] = {-1, 1, 0, 0, -1, 1, 1, -1};
int ddy[8] = {0, 0, -1, 1, -1, -1, 1, 1};

void init() {
    for(int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            visit[i][j] = false;
        }
    }
}

void bfs(int row, int col) {
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(row, col), 0));

    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int time = q.front().second;
        q.pop();
        if(map[x][y] == 1) {
            maxArea = max(maxArea, time);
            break;
        }
        for (int i=0;i<8;i++) {
            int dx = x + ddx[i];
            int dy = y + ddy[i];
            if(dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
            if(!visit[dx][dy]) {
                visit[dx][dy] = true;
                q.push(make_pair(make_pair(dx, dy), time + 1));
            }
        }
    }
    init();
}

int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> map[i][j];
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(!visit[i][j] && map[i][j] == 0) {
                visit[i][j] = true;
                bfs(i, j);
            }
        }
    }
    cout << maxArea << "\n";
}