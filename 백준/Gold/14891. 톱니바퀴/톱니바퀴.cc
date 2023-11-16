#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

string wheel[5];
bool visit[5];
int k;
queue<pair<int, int> > q;

void bfs(int wheelNum, int direct) {
    q.push(make_pair(wheelNum, direct));
    visit[wheelNum] = true;
    queue<pair<int, int> > w;
    while (!q.empty())
    {
        int now = q.front().first;
        int d = q.front().second;
        w.push(make_pair(now, d));
        q.pop();
        if(now - 1 > 0 && !visit[now-1]) {
            if(wheel[now][6] != wheel[now-1][2]) {
                visit[now-1] = true;
                q.push(make_pair(now-1, d*(-1)));
            }
        }
        if(now + 1 <= 4 && !visit[now+1]) {
            if(wheel[now][2] != wheel[now+1][6]) {
                visit[now+1] = true;
                q.push(make_pair(now+1, d*(-1)));
            }
        }
    }
    while (!w.empty())
    {
        int now = w.front().first;
        int d = w.front().second;
        w.pop();
        string tmp = wheel[now];
        if(d == 1) {
            for(int i=0;i<8;i++) {
                wheel[now][i] = tmp[((i-1)+8) % 8];
            }
        }
        else if(d == -1) {
            for(int i=0;i<8;i++) {
                wheel[now][i] = tmp[(i+1)% 8];
            }
        }
    }
}

int main() {
    for(int i=1;i<=4;i++)
        cin >> wheel[i];

    cin >> k;
    for (int i=0;i<k;i++) {
        int wheelNum, direct;
        cin >> wheelNum >> direct;
        bfs(wheelNum, direct);
        for(int j=1;j<=4;j++) {
            visit[j] = false;
        }
    }
    int answer = 0;
    for(int i=1;i<=4;i++) {
        if(wheel[i][0] == '1') {
            answer += pow(2, i-1);
        }
    }
    cout << answer << "\n";
    return 0;
}