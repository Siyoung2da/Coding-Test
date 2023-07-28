#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int minCount = 100000000;
int minLen = 100001;
bool flag;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, s;
    cin >> n >> s;
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    
    int left = 0, right = 0;
    int sum = 0;
    int len = 0;
    while (right < n)
    {
        sum += arr[right];
        
        while(sum >= s) {
            len = right - left + 1;
            minLen = min(minLen, len);
            sum -= arr[left];
            left++;

            flag = true;
            continue;
        }
        

        right++;
        
    }

    if(!flag) minLen = 0;

    cout << minLen << "\n";

}