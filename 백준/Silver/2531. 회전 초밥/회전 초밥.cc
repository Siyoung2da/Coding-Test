#include <iostream>
#include <algorithm>
using namespace std;

int plate[30001];
int sushi[3001];
int maxCount;

int main()
{
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> plate[i];
    }

    int cnt = 0, eat = 0;
    int left = 0, right = 0;
    while (left < n)
    {
        if(cnt < k) {
            if(sushi[plate[right]] == 0) {
                eat++;
            }
            sushi[plate[right]]++;
            cnt++;
            if(cnt==k) {
                continue;
            }
            right = (right + 1) % n;
        }
        else if(cnt == k) {
            if(sushi[c] == 0) {
                maxCount = max(maxCount, eat + 1);
            }
            else maxCount = max(maxCount, eat);

            right = (right + 1) % n;
            if(sushi[plate[right]] == 0) {
                eat++;
            }
            sushi[plate[right]]++;

            if(sushi[plate[left]] == 1) {
                eat--;
            }
            sushi[plate[left]]--;
            left++;
            
        }
        
        // cout << left << ", " << right << " : " << eat << "\n";
    }
    cout << maxCount << "\n";
}