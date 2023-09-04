#include <iostream>
#include <deque>
using namespace std;

int N, M, S;
int graph[1001][1001];
deque<int> deq_n;
bool visit[1001];

void dfs(int s)
{
    visit[s] = true;
    cout << s << " ";

    for (int i = 1; i <= N; i++)
    {
        int k = graph[s][i];
        if (!visit[i] && k==1)
        {
            dfs(i);
        }
    }
}
void bfs(int s)
{
    visit[s] = true;
    deq_n.push_back(s);
    while (!deq_n.empty())
    {
        int n = deq_n.front();
        deq_n.pop_front();
        cout << n << " ";
        for (int i = 1; i <= N; i++)
        {
            int k = graph[n][i];
            if (!visit[i] && k==1)
            {
                visit[i] = true;
                deq_n.push_back(i);
            }
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> S;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1; 
    }
    
    dfs(S);
    cout << "\n";
    for (int i = 0; i <= 1000; i++)
        visit[i] = false;
    bfs(S);
}