#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, l, r, answer;
int map[51][51];
bool visit[51][51];
int ddx[4] = {-1, 1, 0, 0};
int ddy[4] = {0, 0, -1, 1};
bool flag;

void bfs(int row, int col) {
    queue<pair<int, int> > q;
    queue<pair<int, int> > q2;
    q.push(make_pair(row, col));
    visit[row][col] = true;
    int total = 0, cnt = 0;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        total += map[x][y];
        cnt++;
        q2.push(make_pair(x, y));
        q.pop();

        for(int i=0;i<4;i++) {
            int dx = x + ddx[i];
            int dy = y + ddy[i];

            if(dx < 0 || dx >= n || dy < 0 || dy >= n) continue;
            if(!visit[dx][dy] && abs(map[dx][dy] - map[x][y]) >= l && abs(map[dx][dy] - map[x][y]) <= r) {
                visit[dx][dy] = true;
                q.push(make_pair(dx, dy));
            }
        }
    }
    if(cnt > 1) flag = true;
    int value = total / cnt;
    while (!q2.empty())
    {
        int x = q2.front().first;
        int y = q2.front().second;
        map[x][y] = value;
        q2.pop();
    }
    
}

void init() {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            visit[i][j] = false;
        }
    }
    flag = false;
}

int main() {
    cin >> n >> l >> r;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> map[i][j];
        }
    }

    int i = 0, j = 0;
    
    while(1) {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {   
                if(!visit[i][j]) {
                    bfs(i, j);
                }
            }  
        }
        if(flag) {
            answer++;
            init();
        }
        else if(!flag) break;
    }
    
    cout << answer << "\n";

}