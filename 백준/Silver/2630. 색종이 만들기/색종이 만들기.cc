#include <iostream>
using namespace std;

int white, blue;
int map[128][128];

void dfs(int x, int y, int N)
{
    int tmp = map[y][x];
    for (int i = y; i < y + N; i++)
    {
        for (int j = x; j < x + N; j++)
        {
            if (tmp != map[i][j])
            {
                dfs(x, y, N/2);
                dfs(x + N/2, y, N/2);
                dfs(x, y + N/2, N/2);
                dfs(x + N/2, y + N/2, N/2);
                return;
            }
        }
    }
    if(tmp == 1) blue++;
    else white++;
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    dfs(0, 0, N);

    cout << white << "\n"
         << blue << "\n";
}