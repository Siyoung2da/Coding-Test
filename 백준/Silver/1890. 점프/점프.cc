#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long map[100][100];
long long dp[100][100];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    dp[map[0][0]][0]++;
    dp[0][map[0][0]]++;

    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(dp[i][j]!=0 && map[i][j] != 0) {
                if (i + map[i][j] < n && j + map[i][j] < n)
                {
                    if(dp[i + map[i][j]][j] != 0)
                        dp[i + map[i][j]][j] += dp[i][j];
                    else 
                        dp[i + map[i][j]][j] = dp[i][j];
                    if(dp[i][j + map[i][j]] != 0)    
                        dp[i][j + map[i][j]] += dp[i][j];
                    else
                        dp[i][j + map[i][j]] = dp[i][j];
                    
                }
                else if (i + map[i][j] < n && j + map[i][j] >= n) {
                    if(dp[i + map[i][j]][j] != 0)
                        dp[i + map[i][j]][j] += dp[i][j];
                    else 
                        dp[i + map[i][j]][j] = dp[i][j];
                }
                else if (i + map[i][j] >= n && j + map[i][j] < n) {
                    if(dp[i][j + map[i][j]] != 0)    
                        dp[i][j + map[i][j]] += dp[i][j];
                    else
                        dp[i][j + map[i][j]] = dp[i][j];
                }
            }
            // cout << "i,j " <<i << j << " : "<< dp[i][j] << " : " << dp[i+map[i][j]][j] << ", " << dp[i][j+map[i][j]] << " and "<<dp[n-1][n-1]<< "\n";
        }
    }
    cout << dp[n - 1][n - 1] << "\n";
}