#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, h;
int map[31][12];
bool flag;

bool check() {
    for(int col=1;col<=n;col++) {
        int rope = col;
        for(int row=1;row<=h;row++) {
            if(map[row][rope-1] == 1) {
                rope = rope-1;
            }
            else if(map[row][rope] == 1) {
                rope = rope + 1;
            }
        }
        if(rope != col) return false;
    }
    return true;
}

void dfs(int row, int col, int cnt, int total) {
    if(cnt > total) {
        return;
    }
    if(cnt == total) {
        if(check()) {
            flag = true;
            return;
        }
    }

    for(int i=row;i<=h;i++) {
        for(int j=1;j<=n;j++) {
            if(map[i][j] == 0 && !flag) {
                map[i][j] = 1;
                dfs(i, j, cnt + 1, total);
                map[i][j] = 0;
            }
        }
    }
    
}

int main() {
    cin >> n >> m >> h;
    for(int i=0;i<m;i++) {
        int row, col;
        cin >> row >> col;
        map[row][col] = 1;
        map[row][col-1] = -1;
        map[row][col+1] = -1;
    }

    if(check()) {
        cout << "0\n";
        return 0;
    }

    for(int total=1;total<=3;total++) {
        dfs(1, 1, 0, total);
        if(flag) {
            cout << total << "\n";
            break;
        }
    }
    if(!flag) cout << -1 << "\n";

    // for(int i=1;i<=h;i++) {
    //     for(int j=1;j<=n;j++) {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}