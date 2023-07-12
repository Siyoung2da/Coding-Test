#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][10];

int main() {
    int n;
    cin >> n;
    
    dp[1][1] = 1;
    dp[1][9] = 1;
    for (int i=2;i<=8;i++) {
        dp[1][i] = 1;
        dp[2][i] = dp[1][i] + 1;
    }    
    dp[2][0] = dp[1][1];
    dp[2][1] = dp[1][0] + dp[1][2];
    dp[2][9] = dp[1][8];

    for (int i=3;i<=n;i++) {
        for(int j=1;j<9;j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
            dp[i][j] %= 1000000000;
        }
        dp[i][0] = dp[i-1][1];
        dp[i][9] = dp[i-1][8];
        dp[i][0] %= 1000000000;
        dp[i][9] %= 1000000000;
    }
    int result = 0;
    // for(int j=1;j<=n;j++) {
    //     for (int i=0;i<10;i++) {
    //         cout << dp[j][i] << " ";
    //     }
    //     cout << "\n";
    // }
    for(int i=0;i<10;i++) {
        result += dp[n][i];
        result %= 1000000000;
    }
    // cout << "\n";
    cout << result << "\n";
}