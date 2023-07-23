#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int> > pq;
vector<pair<int, int> > vec;



int main() {
    cin >> n;
    for(int i=0;i<n;i++) 
    {
        int start, end;
        cin >> start >> end;
        vec.push_back(make_pair(start, end));
    }

    sort(vec.begin(), vec.end());

    pq.push(vec[0].second);
    for(int i=1;i<n;i++) {
        if(vec[i].first >= pq.top()) {
            pq.pop();
            pq.push(vec[i].second);
        }
        else {
            pq.push(vec[i].second);
        }
    }
    cout << pq.size() << "\n";
}