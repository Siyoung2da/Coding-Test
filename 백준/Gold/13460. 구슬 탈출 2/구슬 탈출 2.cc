#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n, m, minCount = 11;
char map[11][11];
int ddx[4] = {-1, 1, 0, 0};
int ddy[4] = {0, 0, -1, 1};

int inversionDirect(int direct) {
    if(direct == 0) return 1;
    else if(direct == 1) return 0;
    else if(direct == 2) return 3;
    else if(direct == 3) return 2;
}

void dfs(int direct, int bx, int by, int rx, int ry, int cnt) {
    if(cnt > 10 || cnt > minCount) return;

    bool flagB = false, flagR = false;

    int newBx = bx + ddx[direct];
    int newBy = by + ddy[direct];
    int Bdist = 0;

    int newRx = rx + ddx[direct];
    int newRy = ry + ddy[direct];
    int Rdist = 0;

    while(1) {
        if(map[newBx][newBy] == '#') break;
        if(map[newBx][newBy] == 'O') {
            flagB = true;
            break;
        }
        newBx += ddx[direct];
        newBy += ddy[direct];
        Bdist++;
    }
    newBx -= ddx[direct];
    newBy -= ddy[direct];

    while(1) {
        if(map[newRx][newRy] == '#') break;
        if(map[newRx][newRy] == 'O') {
            flagR = true;
            break;
        }
        newRx += ddx[direct];
        newRy += ddy[direct];
        Rdist++;
    }
    newRx -= ddx[direct];
    newRy -= ddy[direct];

    if(flagB == true) return;
    else {
        if(flagR == true) {
            minCount = min(minCount, cnt);
            return;
        }
    }

    if(newRx == newBx && newRy == newBy) {
        if(Rdist > Bdist) {
            newRx -= ddx[direct];
            newRy -= ddy[direct];
        }
        else {
            newBx -= ddx[direct];
            newBy -= ddy[direct];
        }
    }

    for(int i=0;i<4;i++) {
        if(i == direct) continue;
        if(i == inversionDirect(direct)) continue;

        dfs(i, newBx, newBy, newRx, newRy, cnt + 1);
    }

}


int main() {
    cin >> n >> m;
    int Bx, By, Rx, Ry;
    for(int i=0;i<n;i++) {
        string str;
        cin >> str;
        for (int j=0;j<str.length();j++) {
            map[i][j] = str[j];
            if(map[i][j] == 'B') {
                Bx = i;
                By = j;
            }
            if(map[i][j] == 'R') {
                Rx = i;
                Ry = j;
            }
        }
    }
    
    for (int i=0;i<4;i++) {
        dfs(i, Bx, By, Rx, Ry, 1);
    }
    if(minCount == 11) minCount = -1;

    cout << minCount << "\n";
}