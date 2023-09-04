#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, k;
bool visit[100001];

void bfs(int n) {
    queue<pair<int, int> > q;
    q.push(make_pair(n, 0));
    visit[n] = true;

    while(!q.empty()) {
        int now = q.front().first;
        int time = q.front().second;
        q.pop();
        if(now == k) {
            cout << time << "\n";
            break;
        }

        for (int i=0;i<3;i++) {
            int newNow;
            if(i == 1) {
                newNow = now - 1;
            }
            else if(i == 2) {
                newNow = now + 1;
            }  
            else {
                newNow = now * 2;
            }
            if (newNow < 0 || newNow > 100000) continue;
            if(!visit[newNow]) {
                q.push(make_pair(newNow, time + 1));
                visit[newNow] = true;
            }
        }
    }
}

int main() {
    cin >> n >> k;
    
    bfs(n);
}