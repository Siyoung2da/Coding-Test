#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M, result = 1000000;
int map[51][51];
bool visit[51][51];
vector<pair<int, int> > vec;

void dfs(int row, int col, int numChicken)
{
    if (numChicken == M)
    {
        int total = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (map[i][j] == 1)
                {
                    int dist = 1000000;
                    for (int k = 0; k < vec.size(); k++)
                    {
                        dist = min(dist, abs(vec[k].first - i) + abs(vec[k].second - j));
                    }
                    total += dist;
                }
            }
        }
        if (result > total)
            result = total;
        return;
    }

    for (int i = row; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == 2 && !visit[i][j])
            {
                vec.push_back(make_pair(i, j));
                visit[i][j] = true;
                dfs(i, j, numChicken + 1);
                visit[i][j] = false;
                vec.pop_back();
            }
        }
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    dfs(0, 0, 0);

    cout << result << "\n";
}