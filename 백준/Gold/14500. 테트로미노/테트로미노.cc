#include <iostream>
#include <algorithm>
using namespace std;

int map[501][501];
bool visit[501][501];
int ddx[4] = {-1, 1, 0, 0};
int ddy[4] = {0, 0, -1, 1};
int N, M;
int maxTotal = -1;

void dfs(int row, int col, int total, int cnt) {
    if(cnt == 4) {
        maxTotal = max(maxTotal, total);
        return;
    }

    for (int i=0;i<4;i++) {
        int dx = row + ddx[i];
        int dy = col + ddy[i];

        if(dx >= 0 && dx < N && dy >=0 && dy <M && !visit[dx][dy]) {
            visit[dx][dy] = true;
            dfs(dx, dy, total + map[dx][dy], cnt + 1);
            visit[dx][dy] = false;
        }
    }

    // ㅏ
    if(row > 0 && row + 1 < N && col + 1 < M) {
        maxTotal = max(maxTotal, (map[row-1][col] + map[row][col] + map[row+1][col] + map[row][col+1]));
    }
    // ㅗ
    if(row > 0 && col > 0 && col + 1 < M) {
        maxTotal = max(maxTotal, (map[row-1][col] + map[row][col] + map[row][col-1] + map[row][col+1]));
    }
    // ㅜ
    if(row + 1 < N && col > 0 && col + 1 < M) {
        maxTotal = max(maxTotal, (map[row+1][col] + map[row][col] + map[row][col-1] + map[row][col+1]));
    }
    // ㅓ
    if(row > 0 && row + 1 < N && col > 0) {
        maxTotal = max(maxTotal, (map[row-1][col] + map[row][col] + map[row+1][col] + map[row][col+-1]));
    }

}

int main() {
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin >> map[i][j];
        }
    }

    for(int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            visit[i][j] = true;
            dfs(i, j, map[i][j], 1);
            visit[i][j] = false;
        }
    }
    cout << maxTotal << "\n";
}