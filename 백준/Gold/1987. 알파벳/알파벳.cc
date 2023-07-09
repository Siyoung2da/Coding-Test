#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C;
string str[20];
char map[20][20];
bool visit[26];
int maxCount;
int ddx[4] = {-1, 1, 0, 0};
int ddy[4] = {0, 0, -1, 1};

void dfs(int row, int col, int total) {
    if(total > maxCount) {
        maxCount = total;
    }
    for (int i=0;i<4;i++) {
        int dx = row + ddx[i];
        int dy = col + ddy[i];

        if(dx < 0 || dx >= R || dy < 0 || dy >= C) continue;
        if(!visit[map[dx][dy] - 65]) {
            visit[map[dx][dy]-65] = true;
            dfs(dx, dy, total + 1);
            visit[map[dx][dy] - 65] = false;
        }
    }
}

int main()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        cin >> str[i];
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            map[i][j] = str[i][j];
        }
    }

    visit[map[0][0] - 65] = true;
    dfs(0, 0, 1);

    cout << maxCount << "\n";

}
