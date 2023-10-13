#include <iostream>
#include <algorithm>

using namespace std;

int n;
int t[17], p[17];
int dp[17];

int main() {
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> t[i] >> p[i];
    }
    
    for(int i=n;i>0;i--) {
        int deadline = i + t[i];
        if(deadline <= n+1) {
            dp[i] = max(dp[i+1], dp[deadline] + p[i]);
        }
        else dp[i] = dp[i+1];
    }
    cout << dp[1] << " ";
}