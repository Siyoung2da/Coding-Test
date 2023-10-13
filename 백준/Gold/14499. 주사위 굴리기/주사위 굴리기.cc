#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, x, y, k;
int map[21][21];
int dice[7];
int ddx[5] = {0, 0, 0, -1, 1}; // right left up down
int ddy[5] = {0, 1, -1, 0, 0};
vector<int> order;

void east() {
    int tmp[7] = {0, dice[1], dice[2], dice[3], dice[4], dice[5], dice[6]};
    dice[1] = tmp[4];
    dice[2] = tmp[2];
    dice[3] = tmp[1];
    dice[4] = tmp[6];
    dice[5] = tmp[5];
    dice[6] = tmp[3];
}
void west() {
    int tmp[7] = {0, dice[1], dice[2], dice[3], dice[4], dice[5], dice[6]};
    dice[1] = tmp[3];
    dice[2] = tmp[2];
    dice[3] = tmp[6];
    dice[4] = tmp[1];
    dice[5] = tmp[5];
    dice[6] = tmp[4];
}
void north() {
    int tmp[7] = {0, dice[1], dice[2], dice[3], dice[4], dice[5], dice[6]};
    dice[1] = tmp[5];
    dice[2] = tmp[1];
    dice[3] = tmp[3];
    dice[4] = tmp[4];
    dice[5] = tmp[6];
    dice[6] = tmp[2];
}
void south() {
    int tmp[7] = {0, dice[1], dice[2], dice[3], dice[4], dice[5], dice[6]};
    dice[1] = tmp[2];
    dice[2] = tmp[6];
    dice[3] = tmp[3];
    dice[4] = tmp[4];
    dice[5] = tmp[1];
    dice[6] = tmp[5];
}

void move(int dir) {
    if(dir == 1) {
        east();
    }
    else if(dir == 2) {
        west();
    }
    else if(dir == 3) {
        north();
    }
    else if(dir == 4) {
        south();
    }
}

int main() {
    cin >> n >> m >> x >> y >> k;
    for (int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> map[i][j];
        }
    }
    
    for(int i=0;i<k;i++) {
        int dir;
        cin >> dir;
        order.push_back(dir);
    }
    
    for(int i=0;i<order.size();i++) {
        int dx = x + ddx[order[i]];
        int dy = y + ddy[order[i]];

        if(dx < 0 || dx >= n || dy < 0 || dy >= m) continue;

        move(order[i]);

        cout << dice[1] << "\n";

        if(map[dx][dy] == 0) {
            map[dx][dy] = dice[6];
        }
        else {
            dice[6] = map[dx][dy];
            map[dx][dy] = 0;
        }
        x = dx;
        y = dy;
    }
}