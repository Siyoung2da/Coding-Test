#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int ddx[4] = {1, 0, 0, -1};
int ddy[4] = {0, -1, 1, 0};
char ch[4] = {'d', 'l', 'r', 'u'};
vector<string> result;
char map[51][51];
bool visit;

void init(int n, int m, int x, int y, int r, int c) {
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if(i == x && j == y) {
                map[i][j] = 'S';
            }
            else if(i == r && j == c) {
                map[i][j] = 'E';
            }
            else {
                map[i][j] = '.';
            }
        }
    }
}

bool flag;
void dfs(int n, int m, int x, int y, int r, int c, int k, int dist, string answer) {
    // cout << x << ", " << y << " : " << answer << " (" << dist << ") and map : " << map[x][y] << "\n";
    if(flag) return;
    if(dist == k) {
        if(map[x][y] == 'E') {
            result.push_back(answer);
            flag = true;
        }
        return;
    }
    int left = (k-dist) - (abs(r - x) + abs(c - y));
    if(left < 0 || left % 2 == 1) {
        return;
    }
    
    for (int i=0;i<4;i++) {
        int dx = x + ddx[i];
        int dy = y + ddy[i];
        string str = answer + ch[i];
        if(dx <= 0 || dx > n || dy <= 0 || dy > m) continue;
        if(!flag || !visit) {
            if(map[dx][dy] == 'E') visit = true;
            dfs(n, m, dx, dy, r, c, k, dist + 1, str);
            if(map[dx][dy] == 'E') visit = false;
        }
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    init(n, m, x, y, r, c);
        
    dfs(n, m, x, y, r, c, k, 0, "");
    if(result.empty()) answer = "impossible";
    else answer = result[0];
    return answer;
}