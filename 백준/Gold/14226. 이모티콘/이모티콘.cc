#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int s;
int visit[2001][2001];
queue<pair<pair<int, int>, int> > q;

void bfs(int s) {
    q.push(make_pair(make_pair(0, 1), 0));
    visit[1][0] = true;
    while(!q.empty()) {
        int clip = q.front().first.first;
        int screen = q.front().first.second;
        int time = q.front().second;
        // cout << "clip : " << clip << " screen : " << screen << " time : " << time << "\n";
        q.pop();
        if(screen == s) {
            cout << time << "\n";
            break;
        }
        for(int i=0;i<3;i++) {
            if(i==0) {
                if(!visit[screen][screen]) {
                    visit[screen][screen] = true;
                    q.push(make_pair(make_pair(screen, screen), time + 1));
                }
            }
            else if(i==1) {
                if(!visit[clip][screen + clip] && screen + clip <= s + clip) {
                    visit[clip][screen + clip] = true;
                    q.push(make_pair(make_pair(clip, screen + clip), time + 1));
                }
            }
            else {
                if(!visit[clip][screen-1] && screen - 1 >= 0) {
                    visit[clip][screen-1] = true;
                    q.push(make_pair(make_pair(clip, screen - 1), time + 1));
                }
            }
        }
        
    }
}

int main() {
    cin >> s;
    bfs(s);
}