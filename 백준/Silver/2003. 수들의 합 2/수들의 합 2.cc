#include <iostream>
using namespace std;

int num[10000];
int sum, cnt;

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += num[j];
            if(sum > m) {
                sum = 0;
                break;
            }
            if(sum == m) {
                
                sum = 0;
                cnt++;
                break;
            }
        }
    }

    cout << cnt << "\n";
}