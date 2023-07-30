#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[301][301];
int result;
int sum[301][301];

int Sum(int row1, int col1, int row2, int col2) {
    int cost = 0;
    for (int i=row1;i<row2;i++) {
        for(int j=col1;j<col2;j++) {
            cost += arr[i][j];
        }
    }
    return cost;
}

int main() {
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin >> arr[i][j];
        }
    }

    sum[1][1] = arr[1][1];

    for(int i=2;i<=n;i++) {
        sum[i][1] = sum[i-1][1] + arr[i][1];
    }
    for(int j=2;j<=m;j++) {
        sum[1][j] = sum[1][j-1] + arr[1][j];
    }    
    for(int i=2;i<=n;i++) {
        for (int j=2;j<=m;j++) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
        }
    }

    for(int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            for(int row=i;row<=n;row++) {
                for(int col=j;col<=m;col++) {
                    int cost = 0;
                    cost = sum[row][col] - sum[row][j-1] - sum[i-1][col] + sum[i-1][j-1];
                    if(cost == 10) result++;
                    else if(cost > 10) break;
                }
            }
        }
    }    
    cout << result << "\n";

}