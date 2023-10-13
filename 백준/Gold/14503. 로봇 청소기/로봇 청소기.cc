#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m, r, c, D;
int map[51][51];
bool clean[51][51];
int ddx[4] = {-1, 0, 1, 0};
int ddy[4] = {0, 1, 0, -1};
queue<pair<pair<int, int>, int> > q;
int answer;

void bfs(int row, int col, int dir) {
    q.push(make_pair(make_pair(row, col), dir));
    answer++;
    clean[row][col] = true;
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        bool flag = false;
        q.pop();

        for(int i=1;i<=4;i++) {
            int dx = x + ddx[((d-i) + 4) % 4];
            int dy = y + ddy[((d-i) + 4) % 4];
            int dd = ((d-i) + 4) % 4;
            
            if(map[dx][dy] == 0 && !clean[dx][dy]) {
                q.push(make_pair(make_pair(dx, dy), dd));
                clean[dx][dy] = true;
                answer++;
                flag = true;
                break;
            }
        }
        if(!flag) {
            int dx = x + ddx[((d + 2) + 4) % 4];
            int dy = y + ddy[((d + 2) + 4) % 4];

            if(map[dx][dy] == 1) {
                return;
            }
            else {
                q.push(make_pair(make_pair(dx, dy), d));
            }
        }
        
    }
}

int main() {
    cin >> n >> m >> r >> c >> D;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> map[i][j];
        }
    }

    bfs(r, c, D);
    cout << answer << "\n";
}