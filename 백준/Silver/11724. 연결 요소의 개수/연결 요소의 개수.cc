#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int graph[1001][1001];
bool visit[1001];

void dfs(int u) {
    for (int v=1;v<=n;v++) {
        if(graph[u][v] == 1 && !visit[v]) {
            visit[v] = true;
            dfs(v);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    int connect = 0;
    for (int i=1;i<=n;i++) {
        if(!visit[i]) {
            connect++;
            visit[i] = true;
            dfs(i);
        }
    }
    cout << connect << "\n";
}