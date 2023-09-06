#include <iostream>
#include <vector>
using namespace std;

int n, l;
int computer[101][101];
bool visit[101];
int num;

void dfs(int start) {
    for(int i=1;i<=n;i++) {
        if(computer[start][i] && !visit[i]) {
            visit[i] = true;
            dfs(i);
            num++;
        }
    }
}

int main() {
    cin >> n >> l;
    for (int i=0;i<l;i++) {
        int com1, com2;
        cin >> com1 >> com2;
        computer[com1][com2] = 1;
        computer[com2][com1] = 1;
    }
    visit[1] = true;
    dfs(1);
    cout << num << "\n";
}