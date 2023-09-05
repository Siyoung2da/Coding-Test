#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int m, n;
int box[1001][1001];
bool visit[1001][1001];
int check[1001][1001];
queue<pair<int, int> > q;
int ddx[] = {-1, 1, 0, 0};
int ddy[] = {0, 0, -1, 1};

void bfs()
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int dx = x + ddx[i];
            int dy = y + ddy[i];
            if (dx > 0 && dx <= n && dy > 0 && dy <= m)
            {
                if (!visit[dx][dy] && box[dx][dy] == 0)
                {
                    visit[dx][dy] = true;
                    check[dx][dy] = check[x][y] + 1;
                    q.push(make_pair(dx, dy));
                }
            }
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> box[i][j];
            if (box[i][j] == 1)
            {
                q.push(make_pair(i, j));
                visit[i][j] = true;
            }
            else if (box[i][j] == -1)
                check[i][j] = -1;
        }
    }

    bfs();

    int min_sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (min_sum < check[i][j])
            {
                min_sum = check[i][j];
            }
            if (box[i][j] == 0 && visit[i][j] == false)
            {
                cout << "-1"
                     << "\n";
                return 0;
            }
        }
    }
    cout << min_sum << "\n";
}