#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<pair<long long, long long> > vec;
priority_queue<long long, vector<long long>, greater<long long> > room;

bool compare(pair<long long, long long> a, pair<long long, long long> b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }

    return a.first < b.first;
}

int main() {
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        long long a, b;
        cin >> a >> b;
        vec.push_back(make_pair(a, b));
    }

    sort(vec.begin(), vec.end(), compare);


    room.push(vec[0].second);
    for (int i=1;i<n;i++) {
        if(vec[i].first >= room.top()) {
            room.pop();
            room.push(vec[i].second);
        }
        else {
            room.push(vec[i].second);
        }
    }
    cout << room.size() << "\n";

}