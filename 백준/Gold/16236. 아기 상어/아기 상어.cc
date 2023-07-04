#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int map[20][20];
bool visit[20][20];

queue<pair<pair<int, int>, int> > q;
vector<pair<pair<int, int>, int> > vec;

int ddx[4] = {-1, 0, 0, 1};
int ddy[4] = {0, -1, 1, 0};
int level = 2;
int eats;
int canEat;
int maxDistance;
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
            {
                canEat++;
            }
            if (map[i][j] == 9)
            {
                visit[i][j] = true;
                q.push(make_pair(make_pair(i, j), 0));
                map[i][j] = 0;
            }
        }
    }
    if (canEat == 0)
    {
        cout << 0 << "\n";
        return 0;
    }

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dist = q.front().second;

        int high = 100000;
        int left = 100000;
        int distance = -1;

        if (vec.size() > 0)
        {
            high = vec[0].first.first;
            left = vec[0].first.second;
            distance = vec[0].second;
            for (int i = 1; i < vec.size(); i++)
            {
                if(distance > vec[i].second) {
                    high = vec[i].first.first;
                    left = vec[i].first.second;
                    distance = vec[i].second;
                }
                else if (distance == vec[i].second) {
                    if (high > vec[i].first.first)
                    {
                        high = vec[i].first.first;
                        left = vec[i].first.second;
                        distance = vec[i].second;
                    }
                    else if (high == vec[i].first.first)
                    {
                        if (left > vec[i].first.second)
                        {
                            left = vec[i].first.second;
                            distance = vec[i].second;
                        }
                    }
                }
                
            }
        }

        if (dist == distance)
        {
            maxDistance = dist;
            eats++;
            canEat--;
            map[high][left] = 0;
            if (eats == level)
            {
                level++;
                eats = 0;
            }
            if (canEat == 0)
            {
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < N; j++)
                    {
                        if (map[i][j] > 0 && map[i][j] < level)
                            canEat++;
                    }
                }
            }

            if (canEat == 0)
            {
                cout << dist << "\n";
                return 0;
            }
            // cout << "eat (" << x + 1 << "," << y + 1 << ") dist = " << dist << " level = " << level << " eats = " << eats << "\n";
            
            while (!q.empty())
                q.pop();
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    visit[i][j] = false;
                }
            }
            q.push(make_pair(make_pair(high, left), distance));
            visit[high][left] = true;
            vec.clear();
            continue;
        }
        // cout << "(" << x+1 << "," << y+1 << ") dist = " << dist << " level = " << level << " eats = " <<  eats << "\n";
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int dx = x + ddx[i];
            int dy = y + ddy[i];
            if (dx < 0 || dx >= N || dy < 0 || dy >= N)
                continue;
            if (!visit[dx][dy] && (map[dx][dy] == 0 || map[dx][dy] == level))
            {
                visit[dx][dy] = true;
                q.push(make_pair(make_pair(dx, dy), dist + 1));
                // cout << "pass (" << dx+1 << "," << dy+1 << ") dist = " << dist+1 << " level = " << level << " eats = " <<  eats << "\n";
            }
            else if (!visit[dx][dy] && map[dx][dy] > 0 && map[dx][dy] < level)
            {
                // x = dx;
                // y = dy;
                // eats++;
                // canEat--;
                // map[dx][dy] = 0;
                // if(eats == level) {
                //     level++;
                //     eats = 0;
                // }
                // if(canEat == 0) {
                //     for(int i=0;i<N;i++) {
                //         for(int j=0;j<N;j++) {
                //             if(map[i][j] > 0 && map[i][j] < level) canEat++;
                //         }
                //     }
                // }

                // while(!q.empty()) q.pop();
                // for (int i=0;i<N;i++) {
                //     for(int j=0;j<N;j++) {
                //         visit[i][j] = false;
                //     }
                // }
                q.push(make_pair(make_pair(dx, dy), dist + 1));
                vec.push_back(make_pair(make_pair(dx, dy), dist + 1));
                visit[dx][dy] = true;
                // if (canEat == 0)
                // {
                //     cout << dist + 1 << "\n";
                //     return 0;
                // }
                // cout << "eat (" << dx + 1 << "," << dy + 1 << ") dist = " << dist + 1 << " level = " << level << " eats = " << eats << "\n";
                break;
            }
        }
    }
    cout << maxDistance << "\n";

    // 6
    // 5 4 3 2 3 4
    // 4 3 2 3 4 5
    // 3 2 9 5 6 6
    // 2 1 2 3 4 5
    // 3 2 1 6 5 4
    // 6 6 6 6 6 6
}