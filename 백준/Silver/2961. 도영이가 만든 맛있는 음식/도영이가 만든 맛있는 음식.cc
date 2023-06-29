#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int N;
long long S[11];
long long B[11];
long long minGap = 1000000;
bool visit[11];
long long X=1, Y, Gap;

void dfs(int start) {
    if (start == N) {
        return ;
    }
    for (int i=start;i<N;i++) {
        if(!visit[i]) {
            X *= S[i];
            Y += B[i];
            Gap = abs(X - Y);
            minGap = min(minGap, Gap);
            visit[i] = true;
            dfs(i + 1);
            visit[i] = false;
            X = X / S[i];
            Y = Y - B[i];
        }
    }
}

int main() {
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> S[i] >> B[i];
    }

    for (int i=0;i<N;i++) {
        visit[i] = true;
        X *= S[i];
        Y += B[i];
        Gap = abs(X - Y);
        minGap = min(minGap, Gap);
        dfs(i);
        X = X / S[i];
        Y = Y - B[i];
        visit[i] = false;
    }
    cout << minGap << "\n";
}