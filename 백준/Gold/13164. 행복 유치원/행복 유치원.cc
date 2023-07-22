#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
vector<long long> vec;
vector<long long> cost;
long long minCost = 0;

int main() {
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        long long num;
        cin >> num;
        vec.push_back(num);
    }
    for(int i=1;i<n;i++) {
        cost.push_back(vec[i] - vec[i-1]);
    }
    sort(cost.begin(), cost.end());
    for(int i=0;i<n-k;i++)
        minCost += cost[i];
    cout << minCost <<"\n";
}