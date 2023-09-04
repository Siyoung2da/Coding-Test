#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int ddx[4] = {-1, 1, 0, 0};
int ddy[4] = {0, 0, -1, 1};

int main() {
    int T;
    cin >> T;
    for (int t=0;t<T;t++) {
        int M, N, K;
        cin >> M >> N >> K;

        int cnt = 0;
        int map[51][51] = {0};
        int visit[51][51] = {0};

        for (int i=0;i<K;i++) {
            int x, y;
            cin >> y >> x;
            map[x][y] = 1;
        }

        for (int i=0;i<=N;i++) {
            for (int j=0;j<=M;j++) {
                if(map[i][j]==1 && visit[i][j]==0) {
                    cnt++;
                    queue<pair<int, int> > q;
                    q.push(make_pair(i, j));
                    visit[i][j] = 1;
                    while(!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for (int k=0;k<4;k++) {
                            int dx = x + ddx[k];
                            int dy = y + ddy[k];
                            if (dx >= 0 && dx <=N && dy >= 0 && dy <= M) {
                                if(visit[dx][dy] == 0 && map[dx][dy] == 1) {
                                    q.push(make_pair(dx, dy));
                                    visit[dx][dy] = 1;
                                }
                            }
                        }
                    } 
                }
            }
        }
        cout << cnt << "\n";
    }
}