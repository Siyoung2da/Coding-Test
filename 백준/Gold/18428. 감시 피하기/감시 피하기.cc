#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
char map[6][6];
vector<pair<int, int> > vec;
vector<pair<int, int> > teacher;
int ddx[4] = {-1, 1, 0, 0};
int ddy[4] = {0, 0, -1, 1};
bool flag;
bool check = true;

void dfs(int index)
{
    if (index == teacher.size())
    {
        if (check)
            flag = true;
        return;
    }

    int row = teacher[index].first;
    int col = teacher[index].second;

    for (int i = 0; i < 4; i++)
    {
        int x = row;
        int y = col;
        // cout << "row, col : " << row << ", " << col << "\n";
        while (1)
        {
            int dx = x + ddx[i];
            int dy = y + ddy[i];
            x = dx;
            y = dy;
            // cout << "(" << dx << ", " << dy << ") = " << map[dx][dy] << "\n";
            if (dx < 0 || dx >= N || dy < 0 || dy >= N)
                break;
            if(map[dx][dy] == 'X') continue;
            if (map[dx][dy] == 'O')
            {
                break;
            }
            if (map[dx][dy] == 'S')
            {
                check = false;
                return;
            }
        }
    }
    dfs(index + 1);
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'X')
            {
                vec.push_back(make_pair(i, j));
            }
            if (map[i][j] == 'T')
            {
                teacher.push_back(make_pair(i, j));
            }
        }
    }

    for (int a = 0; a < vec.size() - 2; a++)
    {
        for (int b = a + 1; b < vec.size() - 1; b++)
        {
            for (int c = b + 1; c < vec.size(); c++)
            {
                char backup[6][6];
                for (int i = 0; i < 6; i++)
                {
                    for (int j = 0; j < 6; j++)
                    {
                        backup[i][j] = map[i][j];
                    }
                }

                map[vec[a].first][vec[a].second] = 'O';
                map[vec[b].first][vec[b].second] = 'O';
                map[vec[c].first][vec[c].second] = 'O';

                if (!flag)
                {
                    check = true;
                    dfs(0);

                    for (int i = 0; i < 6; i++)
                    {
                        for (int j = 0; j < 6; j++)
                        {
                            map[i][j] = backup[i][j];
                        }
                    }
                }
                else
                {
                    cout << "YES"
                         << "\n";
                    return 0;
                }
            }
        } 
    }
    cout << "NO"
         << "\n";
}