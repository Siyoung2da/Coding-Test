#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, maxValue = 2;
int map[21][21];
bool visit[21][21];
int ddx[4] = {-1, 1, 0, 0};
int ddy[4] = {0, 0, -1, 1};
int total;
void move(int direction, int x, int y)
{
    int tmp = map[x][y];
    map[x][y] = 0;
    int dx = x + ddx[direction];
    int dy = y + ddy[direction];
    while (1)
    {
        if (dx < 0 || dx >= n || dy < 0 || dy >= n)
        {
            map[dx - ddx[direction]][dy - ddy[direction]] = tmp;
            break;
        }
        else if (map[dx][dy] != 0 && map[dx][dy] != tmp)
        {
            map[dx - ddx[direction]][dy - ddy[direction]] = tmp;
            break;
        }
        else if (map[dx][dy] == tmp)
        {
            if (!visit[dx][dy])
            {
                visit[dx][dy] = true;
                map[dx][dy] *= 2;
                break;
            }
            else
            {
                map[dx - ddx[direction]][dy - ddy[direction]] = tmp;
                break;
            }
        }
        dx += ddx[direction];
        dy += ddy[direction];
    }
}

void dfs(int direction, int cnt)
{

    int back[21][21] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            back[i][j] = map[i][j];
        }
    }

    for (int dir = 0; dir < 4; dir++)
    {

        if (direction == 0)
        {
            for (int j = 0; j < n; j++)
            {
                for (int i = 0; i < n; i++)
                {
                    if (map[i][j] != 0)
                    {
                        move(direction, i, j);
                    }
                }
            }
        }
        else if (direction == 1)
        {
            for (int j = 0; j < n; j++)
            {
                for (int i = n - 1; i >= 0; i--)
                {
                    if (map[i][j] != 0)
                    {
                        move(direction, i, j);
                    }
                }
            }
        }
        else if (direction == 2)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (map[i][j] != 0)
                    {
                        move(direction, i, j);
                    }
                }
            }
        }
        else if (direction == 3)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = n - 1; j >= 0; j--)
                {
                    if (map[i][j] != 0)
                    {
                        move(direction, i, j);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                visit[i][j] = false;
        }

        // cout << "Total : " << total << ", 방향은 " << direction << " cnt 는 " << cnt << " \n";
        // total++;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << map[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        if (cnt >= 5)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    maxValue = max(maxValue, map[i][j]);
                }
            }
            return;
        }

        dfs(dir, cnt + 1);
        for (int a = 0; a < n; a++)
        {
            for (int b = 0; b < n; b++)
            {
                map[a][b] = back[a][b];
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < 4; i++)
    {
        dfs(i, 1);
    }

    cout << maxValue << "\n";
}
