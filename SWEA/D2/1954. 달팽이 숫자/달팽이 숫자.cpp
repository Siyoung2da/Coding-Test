#include <iostream>
#include <algorithm>
using namespace std;

int map[11][11];
int T, n;
int ddx[4] = {0, 1, 0, -1};
int ddy[4] = {1, 0, -1, 0};

void dfs(int row, int col, int cnt, int direct) {
    int dx = row + ddx[direct];
    int dy = col + ddy[direct];

    if(cnt == n*n) {
        return;
    }
    if(dx < 0 || dx >= n || dy < 0 || dy >= n || map[dx][dy] > 0) {
        dx = row + ddx[(direct + 1) % 4];
        dy = col + ddy[(direct + 1) % 4];
        direct = (direct + 1) % 4;
    }
    map[dx][dy] = cnt + 1;
    // cout << row << ", " << col <<  " - direct : " << direct << "\n";
    dfs(dx, dy, cnt + 1, direct);
    
}

void init() {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            map[i][j] = 0;
        }
    }
}

int main() {
    cin >> T;

    for(int t=0;t<T;t++) {
        cin >> n;
        init();

        map[0][0] = 1;
        dfs(0, 0, 1, 0);

        cout << "#" << t+1 << "\n";
        for (int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout << map[i][j] << " ";
            }
            cout << "\n";
        }
    }

}