#include <iostream>
using namespace std;

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;

    int num[10001];
    char who[10001];
    
    for (int i=1;i<=K;i++) {
        int R;
        char P;
        cin >> R >> P;
        num[i] = R;
        who[i] = P;
    }
    int check[26] = {1};

    if (num[Q] == 0) {
        cout << "-1";
        return 0;
    }

    for (int i=1;i<=K;i++) {
        if(num[Q] <= num[i]) {
            check[int(who[i] - 65)] = 1;
        }
    }
    string result = "";
    for (int i=0;i<N;i++) {
        if(check[i] == 0) {
            result += char(i + 65);
        }
    }
    for (int i=0;i<result.length()-1;i++) {
        cout << result[i] << " ";
    }
    cout << result[result.length()-1] << "\n";
    
}