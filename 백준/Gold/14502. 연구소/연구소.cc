#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int map[9][9];
vector<pair<int, int> > zero_vec;
queue<pair<int, int> > q;
int ddx[4] = {-1, 1, 0, 0};
int ddy[4] = {0, 0, -1, 1};
int maxTotal = -1;
bool visit[9][9];

void bfs()
{
    int backup[9][9];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            backup[i][j] = map[i][j];
        }
    }

    for (int a = 0; a < zero_vec.size() - 2; a++)
    {
        for (int b = a + 1; b < zero_vec.size() - 1; b++)
        {
            for (int c = b + 1; c < zero_vec.size(); c++)
            {

                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                    {
                        visit[i][j] = false;
                        map[i][j] = backup[i][j];
                        if (map[i][j] == 2)
                        {
                            visit[i][j] = true;
                            q.push(make_pair(i, j));
                        }
                    }
                }

                map[zero_vec[a].first][zero_vec[a].second] = 1;
                map[zero_vec[b].first][zero_vec[b].second] = 1;
                map[zero_vec[c].first][zero_vec[c].second] = 1;

                while(!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int i=0;i<4;i++) {
                        int dx = x + ddx[i];
                        int dy = y + ddy[i];

                        if(dx < 0 || dx >= N || dy < 0 || dy >= M) continue;
                        if(map[dx][dy] == 0 && !visit[dx][dy]) {
                            visit[dx][dy] = true;
                            q.push(make_pair(dx, dy));
                            map[dx][dy] = 2;
                        }
                    }
                }
                int total = 0;
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                    {
                        if(map[i][j] == 0) total++;
                    }
                }
                maxTotal = max(maxTotal, total);
            }
        }
    } 
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 0)
            {
                zero_vec.push_back(make_pair(i, j));
            }
        }
    }
    bfs();
    cout << maxTotal << "\n";
}