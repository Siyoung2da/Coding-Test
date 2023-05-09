#include <iostream>
using namespace std;

int N, minus_one, zero, plus_one;
int paper[2188][2188];

void dfs (int row, int col, int N) {
    int check = paper[row][col];
    for (int i=row;i<row+N;i++) {
        for (int j=col;j<col+N;j++) {
            if (check != paper[i][j]) {
                dfs(row, col, N/3);
                dfs(row, col + N/3, N/3);
                dfs(row, col + N*2/3, N/3);

                dfs(row + N/3, col, N/3);
                dfs(row + N/3, col + N/3, N/3);
                dfs(row + N/3, col + N*2/3, N/3);

                dfs(row + N*2/3, col, N/3);
                dfs(row + N*2/3, col + N/3, N/3);
                dfs(row + N*2/3, col + N*2/3, N/3);
                return;
            }
        }
    }
    if(check == -1) minus_one++;
    else if(check == 0) zero++;
    else plus_one++;
}

int main() {
    cin >> N;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cin >> paper[i][j];
        }
    }
    dfs(0, 0, N);
    cout << minus_one << "\n" << zero << "\n" << plus_one << "\n";
}