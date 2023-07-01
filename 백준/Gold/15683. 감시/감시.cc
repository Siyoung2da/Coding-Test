#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int map[9][9];
int ddx[4] = {0, -1, 0, 1}; // right, up, left, down
int ddy[4] = {1, 0, -1, 0};
vector<pair<int, int> > vec;
int minTotal = 100000;

void see(int row, int col, int index) {
    index %= 4;
    while(1) {
        int new_row = row + ddx[index];
        int new_col = col + ddy[index];
        row = new_row;
        col = new_col;
        if(new_row < 0 || new_row >= N || new_col < 0 || new_col >= M) return;
        if(map[new_row][new_col] == 6) return;
        if(map[new_row][new_col] != 0) continue;
        map[new_row][new_col] = '#';
        
    }
}

void dfs(int index) {
    if(index == vec.size()) {
        int total = 0;
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if(map[i][j] == 0) total++;
            }
        }
        minTotal = min(minTotal, total);
        return;
    }

    int row = vec[index].first;
    int col = vec[index].second;
    int backup[9][9];
    for (int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            backup[i][j] = map[i][j];
        }
    }

    for(int dir=0;dir<4;dir++) {
        for (int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                backup[i][j] = map[i][j];
            }
        }
        if(map[row][col] == 1) {
            see(row, col, dir);
        }
        else if(map[row][col] == 2) {
            see(row, col, dir);
            see(row, col, dir + 2);
        }
        else if(map[row][col] == 3) {
            see(row, col, dir);
            see(row, col, dir + 1);
        }
        else if(map[row][col] == 4) {
            see(row, col, dir);
            see(row, col, dir + 1);
            see(row, col, dir + 2);
        }
        else if(map[row][col] == 5) {
            see(row, col, dir);
            see(row, col, dir + 1);
            see(row, col, dir + 2);
            see(row, col, dir + 3);
        }
        dfs(index + 1);
        for (int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                map[i][j] = backup[i][j];
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin >> map[i][j];
            if(map[i][j] >=1 && map[i][j] <=5) {
                vec.push_back(make_pair(i, j));
            }
        }
    }

    dfs(0);
    cout << minTotal << "\n";

}