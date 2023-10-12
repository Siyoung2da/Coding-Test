#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

int map[101][101];
bool visit[101][101];
int n, k, l, sec;
int ddx[4] = {-1, 0, 1, 0};
int ddy[4] = {0, -1, 0, 1};
bool flag;
deque<pair<pair<int, int>, int> > snake;
vector<pair<int, char> > vec;

void move(int t, int dir)
{
    while (sec <= t)
    {
        int x = snake.front().first.first;
        int y = snake.front().first.second;
        int d = snake.front().second;
        
        // for(int i=1;i<=n;i++) {
        //     for(int j=1;j<=n;j++) {
        //         cout << visit[i][j];
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
        int dx = x + ddx[d];
        int dy = y + ddy[d];
        sec++;
        // cout << "head : " <<  dx << ", " << dy << " map " << map[dx][dy] << " __ time : " << sec << " & t : " << t << " (dir : " << d << ") " << dir<< " <> " << (d+dir) % 4 << "\n";
        if (dx <= 0 || dx > n || dy <= 0 || dy > n)
        {
            flag = true;
            return;
        }
        if (map[dx][dy] == 1)
        {
            map[dx][dy] = 0;
            visit[dx][dy] = true;
            if(sec == t) {
                snake.push_front(make_pair(make_pair(dx, dy), (d + dir + 4) % 4));
                break;
            }
            else
                snake.push_front(make_pair(make_pair(dx, dy), d));
            
        }
        else if (map[dx][dy] == 0)
        {
            if (!visit[dx][dy])
            {
                visit[dx][dy] = true;
                if(sec == t) {
                    snake.push_front(make_pair(make_pair(dx, dy), (d + dir + 4) % 4));
                    visit[snake.back().first.first][snake.back().first.second] = false;
                    snake.pop_back();
                    break;
                }
                else {
                    snake.push_front(make_pair(make_pair(dx, dy), d));
                    visit[snake.back().first.first][snake.back().first.second] = false;
                    snake.pop_back();
                }
            }
            else if (visit[dx][dy]) {
                flag = true;
                return;
            }
        }
        
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
    }
    cin >> l;

    snake.push_back(make_pair(make_pair(1, 1), 3));
    visit[1][1] = true;

    for (int i = 0; i < l; i++)
    {
        int x;
        char c;
        cin >> x >> c;
        vec.push_back(make_pair(x, c));
    }
    for(int i=0;i<vec.size();i++) {
        if(!flag) {
            if(vec[i].second == 'L')
                move(vec[i].first, 1);
            if(vec[i].second == 'D')
                move(vec[i].first, -1);
        }
        else 
            break;
    }
    if(!flag) move(10001, 1);
    cout << sec << "\n";
}