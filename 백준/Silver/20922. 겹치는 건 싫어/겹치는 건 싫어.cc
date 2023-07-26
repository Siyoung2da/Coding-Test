#include <iostream>
#include <algorithm>
using namespace std;

int arr[200001];
int cnt[100001];
int maxLength;

int main() {
    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    int left = 0, right = 0;
    int len = 0;

    while(right<n) {
        len++;
        cnt[arr[right]]++;
        if(cnt[arr[right]] > k) {
            while (cnt[arr[right]] > k)
            {
                cnt[arr[left]]--;
                len--;
                left++;
                if(cnt[arr[right]] <= k) {
                    break;
                }
            }
        }
        right++;
        maxLength = max(maxLength, len);
    }
    cout << maxLength << "\n";
}