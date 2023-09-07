#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
queue<pair<int, int> > q;
vector<bool> visit(200001, false);
int answer;
int minTime = 1000000;

void bfs(int n, int k)
{
    q.push(make_pair(n, 0));
    visit[n] = true;
    while (!q.empty())
    {
        int now = q.front().first;
        int time = q.front().second;
        visit[now]= true;
        // cout << now << ", " << time << " : {" << minTime << ", " << answer << "}\n";
        q.pop();
        if (now == k)
        {
            if (minTime == time)
            {
                answer++;
            }
            else if (minTime > time)
            {
                minTime = time;
                answer = 1;
            }
            continue;
        }
        for (int i = 0; i < 3; i++)
        {
            if (i == 0)
            {
                int next = now - 1;
                if (!visit[next] && next >= 0)
                {       
                    q.push(make_pair(next, time + 1));
                }
            }
            else if (i == 1)
            {
                int next = now + 1;
                if (!visit[next] && next <= k)
                {
                    q.push(make_pair(next, time + 1));
                }
            }
            else
            {
                int next = 2 * now;
                if (!visit[next] && next < k * 2) 
                {
                    q.push(make_pair(next, time + 1));
                }
            }
        }
    }
}

int main()
{
    cin >> n >> k;
    bfs(n, k);
    cout << minTime << "\n"
         << answer << "\n";
}