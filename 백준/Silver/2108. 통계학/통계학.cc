#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> vec;
    int count[8001] = {0};
    double avg = 0;
    for (int i=0;i<N;i++) {
        int num;
        cin >> num;
        avg += num;
        count[num+4000]++;
        vec.push_back(num);
    }
    avg = avg / N;
    if (avg > 0) 
        cout << int(avg + 0.5)<< "\n";
    else
        cout << int(avg - 0.5)<< "\n";
    
    sort(vec.begin(), vec.end());
    cout << vec[N/2] << "\n";

    int max_cnt = -1;
    int cnt_num = 0;
    bool check = false;
    for (int i=0;i<8001;i++) {
        if(count[i] > max_cnt) {
            max_cnt = count[i];
            cnt_num = i-4000;
            check = false;
        }
        else if(count[i] == max_cnt) {
            if(!check) {
                cnt_num = i-4000;
                check = true;
            }
        }
    }
    cout << cnt_num << "\n";

    cout << vec[N-1] - vec[0] << "\n";

}