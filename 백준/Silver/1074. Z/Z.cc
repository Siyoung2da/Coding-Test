#include <iostream>
#include <cmath>
using namespace std;

int N, r, c, result;

void dfs(int row, int col, int N) {
    if (row == r && col == c) {
        cout << result << "\n"; 
        return;
    }
    if (r >= row && r < row + N && c >= col && c < col + N) {
        dfs(row, col, N/2);
        dfs(row, col + N/2, N/2);
        dfs(row + N/2, col, N/2);
        dfs(row + N/2, col + N/2, N/2);
    }
    else {
        result += N * N;
    }
}

int main() {
    cin >> N >> r >> c;
    dfs(0, 0, pow(2, N));    
}