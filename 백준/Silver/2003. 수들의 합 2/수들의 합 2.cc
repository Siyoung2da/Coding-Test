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


    int left = 0, right = 0;
    while (right <= n)
    {
        if(sum > m) {
            sum -= num[left++];
        }
        if(sum == m) {
            cnt++;
            sum += num[right++];
        }
        if(sum < m) {
            sum += num[right++];
        }
    }

    cout << cnt << "\n";
}