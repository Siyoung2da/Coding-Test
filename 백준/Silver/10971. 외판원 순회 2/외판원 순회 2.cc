#include <iostream>
#include <algorithm>
using namespace std;

int w[11][11];
int N;
int minDistance = 10000000;
int start;
bool visit[11];
void dfs(int nowCity, int cityNum, int cnt)
{
    if (cityNum == N)
    {
        if(w[nowCity][start] != 0) {
            minDistance = min(minDistance, cnt + w[nowCity][start]);
        }
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (!visit[i] && w[nowCity][i] != 0)
        {
            visit[i] = true;
            dfs(i, cityNum + 1, cnt + w[nowCity][i]);
            visit[i] = false;
        }
    }
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> w[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        start = i;
        visit[i] = true;
        dfs(i, 1, 0);
        visit[i] = false;
    }
    cout << minDistance << "\n";
}