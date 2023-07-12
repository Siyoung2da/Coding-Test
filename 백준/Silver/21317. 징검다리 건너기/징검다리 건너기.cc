#include <iostream>
#include <algorithm>
using namespace std;

int dp[21][2];
int stone[21][2];

int main() {
    int n, k;
    cin >> n;
    for (int i=1;i<n;i++) {
        cin >> stone[i][0] >> stone[i][1];
    }
    cin >> k;

    for(int i=1;i<=n;i++) {
        dp[i][0] = 5000;
        dp[i][1] = 5000;
    }

    dp[1][0] = 0;
    dp[2][0] = stone[1][0];
    dp[3][0] = min(dp[2][0] + stone[2][0], dp[1][0] + stone[1][1]);
    
    for(int i=4;i<=n;i++) {
        dp[i][0] = min(dp[i-2][0] + stone[i-2][1], dp[i-1][0] + stone[i-1][0]);
        dp[i][1] = min(min(dp[i-2][1] + stone[i-2][1], dp[i-1][1] + stone[i-1][0]), dp[i-3][0] + k);
    }

    cout << min(dp[n][0], dp[n][1]) << "\n";
}