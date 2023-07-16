#include <iostream>
#include <algorithm>
using namespace std;

int c, n;
int city[21][2];    // 얼마, 사람 수
int dp[100001];   // 사람 수
int main()
{
    cin >> c >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> city[i][0] >> city[i][1];
    }
    
    for (int i = 1; i <= 100001; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i - city[j][0] >= 0) {
                dp[i] = max(dp[i], dp[i - city[j][0]] + city[j][1]);
            }
        }
    }
    for (int i=0;i<=100001;i++) {
        if(dp[i] >= c) {
            cout << i <<"\n";
            break;
        }
    }
    
}