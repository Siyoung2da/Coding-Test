#include <iostream>
#include <queue>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t=0;t<T;t++) {
        int N, M;
        cin >> N >> M;

        queue<pair<int, int> >q;
        priority_queue<int, vector<int>, less<int> > pq;

        for (int i=0;i<N;i++) {
            int importance;
            cin >> importance;
            q.push(make_pair(i, importance));
            pq.push(importance);
        }
        int cnt = 0;
        while(1) {
            int index = q.front().first;
            int value = q.front().second;
            q.pop();

            if(value == pq.top()) {
                pq.pop();
                cnt++;
                if(index == M) {
                    cout << cnt << "\n";
                    break;
                }
            }
            else {
                q.push(make_pair(index, value));
                
            }
        } 
    }
}