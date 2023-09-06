#include <iostream>
#include <queue>
using namespace std;

int n, m;
char map[101][101];
bool visit[101][101];
int ddx[4] = {-1, 1, 0, 0};
int ddy[4] = {0, 0, -1, 1};
int blue, white;
queue<pair<int, int> > q;

void bfs(int row, int col, char c) {
    q.push(make_pair(row, col));
    int num = 1;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int dx = x + ddx[i];
            int dy = y + ddy[i];
            if(dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
            if(c == 'W') {
                if(!visit[dx][dy] && map[dx][dy] == 'W') {
                    visit[dx][dy] = true;
                    q.push(make_pair(dx, dy));
                    num++;
                }
            }
            else if(c == 'B') {
                if(!visit[dx][dy] && map[dx][dy] == 'B') {
                    visit[dx][dy] = true;
                    q.push(make_pair(dx, dy));
                    num++;
                }
            }
        }
    }
    if(c == 'W') white += num * num;
    else if(c == 'B') blue += num * num;
}

int main() {
    cin >> m >> n;

    for (int i=0;i<n;i++) {
        string str;
        cin >> str;
        for(int j=0;j<m;j++) {
            map[i][j] = str[j];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(!visit[i][j]) {
                visit[i][j] = true;
                if(map[i][j] == 'W')
                    bfs(i, j, 'W');
                else bfs(i, j, 'B');
            }
        }
    }
    cout << white << "\n" << blue << "\n";
}