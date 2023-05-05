#include <iostream>
using namespace std;

bool check[10001];

int d(int n)
{
    int num = n;
    while (n > 0)
    {
        num += n % 10;
        n = n / 10;
    }
    return num;
}

int main()
{
    for (int i = 0; i < 10001; i++)
    {
        int num = d(i);
        if (num > 10000)
            continue;
        check[num] = true;
    }
    for (int i = 0; i < 10001; i++)
    {
        if (!check[i])
        {
            cout << i << "\n";
        }
    }
}