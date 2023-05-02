#include <iostream>
using namespace std;

int main() {
    int T;
    int result = 0;
    cin >> T;

    for (int t=0;t<T;t++) {
        int alpha[26] = {0};
        result++;
        string str;
        cin >> str;
        for (int i=0;i<str.length();i++) {
            alpha[str[i]-97] = 1;
            if(i+1<str.length()) {
                if(str[i+1] != str[i] && alpha[str[i+1]-97] == 1) {
                    result--;
                    break;
                }
            }
        }
    }
    cout << result << "\n";
    
}