#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long m;
long long arr[100001];
long long minCount = 2000000000;

int main() {
    cin >> n >> m;
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    
    int left = 0, right = 0;
    long long cnt = 0;
    while(1) {
        cnt = arr[right] - arr[left];
        if(cnt == m) {
            cout << m << "\n";
            return 0;
        }
        if(cnt > m) {
            minCount = min(minCount, cnt);
            left++;
        }
        else {
            right++;
        }
        if(right >= n) break;
    }
    cout << minCount << "\n";
}