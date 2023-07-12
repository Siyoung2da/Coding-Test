#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int map[1025][1025];
int dp[1025][1025];
vector<int> result;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> map[i][j];
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(j==1) dp[i][j] = dp[i-1][n] + map[i][j];
            else dp[i][j] = dp[i][j-1] + map[i][j];
        }
    }
    for (int i=1;i<=n;i++) {
        dp[i][0] = dp[i-1][n];
    }
    // 1 2 3 4
    // 2 3 4 5
    // 3 4 5 6
    // 4 5 6 7
    for(int t=0;t<m;t++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int num = 0;

        for(int i=x1;i<=x2;i++) {
            num += (dp[i][y2] - dp[i][y1-1]);
        }  
        result.push_back(num);
    }
    // cout << "\n";
    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=n;j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    for (int i=0;i<m;i++) {
        cout << result[i] << "\n";
    }
}