#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, d;
int map[16][15];
bool visit[15][15];
bool killVisist[15][15];
int maxKill;
queue<pair<pair<int, int>, int> > q;
vector<pair<pair<int, int>, int> > vec;
vector<pair<int, int> > v;
int ddx[3] = {0, -1, 0};
int ddy[3] = {-1, 0, 1};
int back[15][15];
void backup()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            map[i][j] = back[i][j];
        }
    }
}

void monsterMove()
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            visit[i][j] = false;
            if (i == n - 1)
            {
                if (map[i][j] == 1)
                {
                    map[i][j] = 0;
                }
            }
            else
            {
                if (map[i][j] == 1)
                {
                    map[i + 1][j] = map[i][j];
                    map[i][j] = 0;
                }
            }
        }
    }
}
bool gameOver()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 1)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    cin >> n >> m >> d;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            back[i][j] = map[i][j];
        }
    }
    for (int a = 0; a < m - 2; a++)
    {
        for (int b = a + 1; b < m - 1; b++)
        {
            for (int c = b + 1; c < m; c++)
            {
                int abc[3] = {a, b, c};
                bool check = false;
                int kill = 0;
                backup();
                while (!gameOver())
                {
                    for (int three = 0;three<3;three++) {
                        q.push(make_pair(make_pair(n, abc[three]), 0));
                        check = false;
                        for(int i=0;i<n;i++) {
                            for(int j=0;j<m;j++) {
                                killVisist[i][j] = false;
                                visit[i][j] = false;
                            }
                        }
                        while (!q.empty())
                        {
                            int row = q.front().first.first;
                            int col = q.front().first.second;
                            int ran = q.front().second;
                            check = false;
                            q.pop();
                            for (int i = 0; i < 3; i++)
                            {
                                int dx = row + ddx[i];
                                int dy = col + ddy[i];
                                int range = ran + 1;
                                if (range > d)
                                    break;
                                if (dx < 0 || dx >= n || dy < 0 || dy >= m)
                                    continue;
                                
                                if(!visit[dx][dy] && map[dx][dy] == 1) {
                                    visit[dx][dy] = true;
                                    v.push_back(make_pair(dx, dy));
                                    check = true;
                                    break;
                                }

                                if(!visit[dx][dy] && map[dx][dy] == 0) {
                                    visit[dx][dy] = true;
                                    vec.push_back(make_pair(make_pair(dx, dy), range));
                                }
                            }
                            if(!check) 
                            {
                                for(int i=0;i<vec.size();i++) {
                                    q.push(make_pair(make_pair(vec[i].first.first, vec[i].first.second), vec[i].second));
                                }
                                vec.clear();
                            }
                            if(check){
                                vec.clear();
                                while(!q.empty())
                                    q.pop();
                            }
                        }
                    }
                    for (int i=0;i<v.size();i++) {
                        if(!killVisist[v[i].first][v[i].second]) {
                            killVisist[v[i].first][v[i].second] = true;
                            map[v[i].first][v[i].second] = 0;
                            kill++;
                        }
                    }
                    v.clear();
                    monsterMove();
                }
                maxKill = max(maxKill, kill);
            }
        }
    }
    cout << maxKill << "\n";
}