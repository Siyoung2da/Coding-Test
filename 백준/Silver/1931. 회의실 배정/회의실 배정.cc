#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> x, pair<int, int> y)
{
    if (x.second == y.second)
    {
        return x.first < y.first;
    }
    else
        return x.second < y.second;
}

int main()
{
    vector<pair<int, int> > vec_num;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        vec_num.push_back(make_pair(x, y));
    }
    sort(vec_num.begin(), vec_num.end(), compare);
    
    int cnt = 1, last;
    last = vec_num[0].second;
    for (int i = 1; i < n; i++)
    {
        if (vec_num[i].first >= last)
        {
            cnt++;
            last = vec_num[i].second;
        }
    }
    cout << cnt << "\n";
}