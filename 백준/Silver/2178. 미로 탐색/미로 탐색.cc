#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

char map[101][101];
bool visit[101][101];
int ddx[4] = {0, 0, -1, 1};
int ddy[4] = {-1, 1, 0, 0};
int n, m;

queue<pair<pair<int, int>, int> > q;

void bfs(int row, int col, int dist) {
    q.push(make_pair(make_pair(row, col), dist));
    visit[row][col] = true;
    int d;

    while(!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        d = q.front().second;
        q.pop();
        if(r == n-1 && c == m-1) {
            cout << d << "\n";
            break;
        }
        for(int i=0;i<4;i++) {
            int dx = r + ddx[i];
            int dy = c + ddy[i];
            int distance = d + 1;
            if(dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
            if(!visit[dx][dy] && map[dx][dy] == '1') {
                q.push(make_pair(make_pair(dx, dy), distance));
                visit[dx][dy] = true;
            }
        }
    }

}

int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        string str;
        cin >> str;
        for(int j=0;j<m;j++) {
            map[i][j] = str[j];
        }
    }
    bfs(0, 0, 1);
}