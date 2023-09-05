#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, home = 0;
vector<int> home_result;
char map[26][26];
bool visit[26][26];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int row, int col)
{
    visit[row][col] = true;
    home++;
    for (int i = 0; i < 4; i++)
    {
        int newrow = dx[i] + row;
        int newcol = dy[i] + col;
        if (newrow < N && newrow >= 0 && newcol < N && newcol >= 0)
            if (!visit[newrow][newcol] && map[newrow][newcol] == '1')
            {
                dfs(newrow, newcol);
            }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string num;
        cin >> num;
        for (int j = 0; j < N; j++)
        {
            map[i][j] = num[j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visit[i][j] && map[i][j] == '1')
            {
                dfs(i, j);
                home_result.push_back(home);
                home = 0;
            }
        }
    }
    sort(home_result.begin(), home_result.end());
    cout << home_result.size() << "\n";
    for (int i = 0; i < home_result.size(); i++)
    {
        cout << home_result[i] << "\n";
    }
}