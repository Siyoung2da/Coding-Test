#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N, L, answer;
int map[101][101];

void Rowroad(int start, int col, int n, int l) {
    int len = 0;
    // int col = 0;
    int value = map[start][col];
    while(col < n) {
        bool flag = false;
        if(value == map[start][col]) {
            len++;
        }
        else if(abs(value-map[start][col]) > 1) return;

        else if(value + 1 == map[start][col]) {
            if(len >= l) {
                value = map[start][col];
                len = 1;
            }
            else {
                return;
            }
        }
        else if(value == map[start][col] + 1) {
            len = 0;
            value = map[start][col];
            flag = true;
            while(1) {
                if(col >= n) {
                    return;
                }
                else {
                    if(value == map[start][col]) {
                        len++;
                        if(len >= l) {
                            col++;
                            if(value < map[start][col]) return;
                            else if(value == map[start][col]) {
                                value = map[start][col];
                            }
                            else if(value == map[start][col] + 1){
                                value = map[start][col - 1];
                            }
                            
                            
                            len = 0;   
                            break;
                        }
                    }
                    else if(value != map[start][col]) {
                        return;
                    }
                    col++;
                }
            }
        }
        // cout << "(" <<start << ", " << col << "\n";
        if(!flag)
            col++;
    }
    // cout << "road : " <<start << "\n";
    answer++;
}

void Colroad(int start, int row, int n, int l) {
    int len = 0;
    // int col = 0;
    int value = map[row][start];
    while(row < n) {
        bool flag = false;
        if(value == map[row][start]) {
            len++;
        }
        else if(abs(value-map[row][start]) > 1) return;

        else if(value + 1 == map[row][start]) {
            if(len >= l) {
                value = map[row][start];
                len = 1;
            }
            else {
                return;
            }
        }
        else if(value == map[row][start] + 1) {
            len = 0;
            value = map[row][start];
            flag = true;
            while(1) {
                if(row >= n) {
                    return;
                }
                else {
                    if(value == map[row][start]) {
                        len++;
                        if(len >= l) {
                            row++;
                            if(value < map[row][start]) return;
                            else if(value == map[row][start]) {
                                value = map[row][start];
                            }
                            else if(value == map[row][start] + 1){
                                value = map[row-1][start];
                            }
                            
                            
                            len = 0;   
                            break;
                        }
                    }
                    else if(value != map[row][start]) {
                        return;
                    }
                    row++;
                }
            }
        }
        // cout << "(" <<start << ", " << row << "\n";
        if(!flag)
            row++;
    }
    // cout << "road : " <<start << "\n";
    answer++;
}

int main() {
    cin >> N >> L;
    for (int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> map[i][j];
        }
    }

    for(int i=0;i<N;i++) {
        Rowroad(i, 0, N, L);
    }
    for(int i=0;i<N;i++) {
        Colroad(i, 0, N, L);
    }

    cout << answer << "\n";
}