#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<bool> visit(200001, false);

struct cmp {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;

void bfs(int n, int k) {
    visit[n] = true;
    pq.push(make_pair(n, 0));

    while(!pq.empty()) {
        int now = pq.top().first;
        int time = pq.top().second;
        visit[now] = true;
        pq.pop();
        if(now == k) {
            cout << time << "\n";
            return ;
        }
        if(now-1 >= 0 && !visit[now-1]) {
            pq.push(make_pair(now-1, time + 1));
        }
        if(now+1 <= k && !visit[now+1]) {
            pq.push(make_pair(now+1, time + 1));
        }
        if(now*2 < 2*k && !visit[2*now]) {
            pq.push(make_pair(now*2, time));
        }
    }
}

int main() {
    cin >> n >> k;
    bfs(n, k);
}