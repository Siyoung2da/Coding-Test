#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a, b, cost;
int min_cost = 10000000;
string map[21];

void func(int row, int col, int k)
{
    if(row + k*3 > n || col + k*3 > m) {
        return ;
    }
    cost = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(i >= row && i < row+k*3 && j>=col && j<col+k*3) {
                if(i>=row+k && i<row+2*k && j>=col+k && j<col+k*3) {
                    if(map[i][j] == '#') {
                        cost += b;
                    }
                }
                else {
                    if(map[i][j] == '.') {
                        cost += a;
                    }
                }
            }
            else {
                if(map[i][j] == '#') {
                    cost += b;
                }
            }
        }
    }
    min_cost = min(min_cost, cost);
    func(row, col, k+1);
}

int main()
{
    cin >> n >> m >> a >> b;

    for (int i = 0; i < n; i++)
    {
        cin >> map[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            func(i, j, 1);
        }
    }
    cout << min_cost << "\n";
}