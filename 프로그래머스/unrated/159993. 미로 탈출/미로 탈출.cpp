#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

queue<pair<pair<int, int>, int> > q;
bool visit[101][101];
int ddx[4] = {-1, 1, 0, 0};
int ddy[4] = {0, 0, -1, 1};

void init() {
    for (int i=0;i<101;i++) {
        for(int j=0;j<101;j++) {
            visit[i][j] = false;
        }
    }
    while(!q.empty()) q.pop();
}

int solution(vector<string> maps) {
    int answer = -1;
    int n = maps.size();
    int m = maps[0].length();
    bool flag = false;
    for(int i=0;i<maps.size();i++) {
        for(int j=0;j<maps[i].length();j++) {
            if(maps[i][j] == 'S') {
                q.push(make_pair(make_pair(i, j), 0));
                visit[i][j] = true;
                break;
            }
        }
    }
    
    while(!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int time = q.front().second;
        q.pop();
        
        if(maps[row][col] == 'E' && flag) {
            answer = time;
            break;
        }
        
        for(int i=0;i<4;i++) {
            int dx = row + ddx[i];
            int dy = col + ddy[i];
            if(dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
            if(!visit[dx][dy] && maps[dx][dy] != 'X') {
                if(maps[dx][dy] == 'L') {
                    init();
                    flag = true;
                    q.push(make_pair(make_pair(dx, dy), time + 1));
                    visit[dx][dy] = true;
                    break;
                }
                q.push(make_pair(make_pair(dx, dy), time + 1));
                visit[dx][dy] = true;
            }
        }
    }
    
    return answer;
}