#include <iostream>
#include <algorithm>
using namespace std;

int dp[10000];
int grape[10000];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> grape[i];
    }

    dp[0] = grape[0];
    dp[1] = grape[0] + grape[1];
    dp[2] = max(max(grape[0] + grape[2], grape[1] + grape[2]), dp[1]);
    for (int i = 3; i < n; i++)
    {
        dp[i] = max(max(dp[i - 2]+ grape[i], dp[i - 3] + grape[i - 1] + grape[i]), dp[i-1]);
    }
    cout << dp[n-1] << "\n";
}