#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
bool visit[200001];
int link[200001];
queue<int> q;
vector<int> answer;

void bfs(int n, int k)
{
    visit[n] = true;
    link[n] = n;
    q.push(n);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        if (now == k)
        {
            answer.push_back(now);
            int parent = link[now];
            while(1) {
                if(parent == n) break;
                answer.push_back(parent);
                parent = link[parent];
            }
            break;
        }
        if (now - 1 >= 0 && !visit[now - 1])
        {
            visit[now-1] = true;
            link[now-1] = now;
            q.push(now-1);
        }
        if (now + 1 <= k && !visit[now + 1])
        {
            visit[now+1] = true;
            link[now+1] = now;
            q.push(now+1);
        }
        if (now * 2 < 2*k && !visit[now * 2])
        {
            visit[now*2] = true;
            link[now*2] = now;
            q.push(now*2);
        }
    }
}

int main()
{
    cin >> n >> k;
    if(n == k) {
        cout << "0\n" << n;
        return 0;
    }
    bfs(n, k);
    cout << answer.size() << "\n" << n << " ";
    for(int i=answer.size()-1;i>=0;i--)
        cout << answer[i] << " ";
    return 0;
}