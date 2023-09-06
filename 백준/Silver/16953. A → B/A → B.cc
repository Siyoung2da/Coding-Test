#include <iostream>
#include <queue>
using namespace std;

long long a, b;
queue<pair<long long, int> > q;

void bfs(long long a, long long b) {
    q.push(make_pair(a, 1));
    while(!q.empty()) {
        long long now = q.front().first;
        int time = q.front().second;
        if(now == b) {
            cout << time << "\n";
            return;
        }
        q.pop();
        for (int i=0;i<2;i++) {
            if(i == 0) {
                long long next = now * 2;
                if(next <= b) {
                    q.push(make_pair(next, time + 1));
                }
            }
            else if(i == 1) {
                long long next = now * 10 + 1;
                if(next <= b) {
                    q.push(make_pair(next, time + 1));
                }
            }
        }
    }
    cout << "-1\n";
}

int main() {
    cin >> a >> b;
    bfs(a, b);
}