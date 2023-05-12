#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    while (1) {
        int k;
        cin >> k;
        if (k==0) break;

        vector<int> lotto;
        vector<int> check;
        
        for (int i=0;i<k;i++) {
            int num;
            cin >> num;
            lotto.push_back(num);
        }
        for (int i=0;i<6;i++) {
            check.push_back(0);
        }
        for (int i=0;i<k-6;i++) {
            check.push_back(1);
        }
        
        // sort(check.begin(), check.end());

        do {
            for (int i=0;i<check.size();i++) {
                if(check[i] == 0) {
                    cout << lotto[i] << " ";
                }
            }
            cout << "\n";
        }while(next_permutation(check.begin(), check.end()));
        cout << "\n";
    }
}