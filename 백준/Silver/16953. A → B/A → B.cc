#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

long long a, b;
long long minCount = 10000000000;

int main() {
    cin >> a >> b;
    queue<pair<long long, long long> > q;
    q.push(make_pair(a, 1));

    while(!q.empty()) {
        long long num = q.front().first;
        long long many = q.front().second;
        q.pop();

        for(int i=0;i<2;i++) {
            long long nextNum = 0;
            if(i==0) {
                nextNum = num * 2;
            }
            else {
                nextNum = num*10 + 1;
            }
            if(nextNum < b) {
                q.push(make_pair(nextNum, many + 1));
            }
            if(nextNum == b) {
                minCount = min(minCount, many+1);
            }
        }
    }
    if(minCount == 10000000000) {
        cout << "-1\n";
        return 0;
    }
    cout << minCount << "\n";
}