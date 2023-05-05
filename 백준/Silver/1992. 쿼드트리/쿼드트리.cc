#include <iostream>
using namespace std;

string map[65];

void dfs(int x, int y, int n)
{
    char check = map[y][x];
    for (int i = y; i < y + n; i++)
    {
        for (int j = x; j < x + n; j++)
        {
            if (check != map[i][j])
            {
                cout << "(";
                dfs(x, y, n / 2);
                dfs(x + (n / 2), y, n / 2);
                dfs(x, y + (n / 2), n / 2);
                dfs(x + (n / 2), y + (n / 2), n / 2);
                cout << ")";
                return;
            }
        }
    }
    cout << check;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> map[i];
    }
    dfs(0, 0, n);
}