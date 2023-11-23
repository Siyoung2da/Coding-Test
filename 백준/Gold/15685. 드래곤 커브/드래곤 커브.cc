#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x, y, d, g, answer;
int ddx[4] = {1, 0, -1, 0};
int ddy[4] = {0, -1, 0, 1};
int map[101][101];

void makeCurve(int x, int y, int d, int g) {
    map[y][x] = 1;
    y += ddy[d];
    x += ddx[d];
    map[y][x] = 1;
    vector<int> vec;
    vec.push_back(d);

    for(int i=0;i<g;i++) {
        int vecSize = vec.size() - 1;
        for(int j=vecSize;j>=0;j--) {
            int nowDirect = (vec[j] + 1) % 4;
            x += ddx[nowDirect];
            y += ddy[nowDirect];
            map[y][x] = 1;
            vec.push_back(nowDirect);
        }
    }
}

void countValue() {
    for(int i=0;i<100;i++) {
        for(int j=0;j<100;j++) {
            if(map[i][j] == 1 && map[i+1][j] == 1 && map[i][j+1] && map[i+1][j+1] == 1) answer++;
        }
    }
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> x >> y >> d >> g;
        makeCurve(x, y, d, g);
    }
    countValue();
    cout << answer << "\n";
}