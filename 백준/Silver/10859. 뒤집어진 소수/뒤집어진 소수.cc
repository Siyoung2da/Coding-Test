#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    string str;
    cin >> str;

    long long num = stoll(str);
    if(num==1) {
        cout << "no" << "\n";
        return 0;
    }
    for (int i=2;i<=sqrt(num);i++) {
        if (num % i == 0) {
            cout << "no" << "\n";
            return 0;
        }
    }

    reverse(str.begin(), str.end());

    for (int i=0;i<str.length();i++) {
        if (str[i] == '3' || str[i] == '4' || str[i] == '7') {
            cout << "no" << "\n";
            return 0;
        }
        else if(str[i] == '6') str[i] = char('9');
        else if(str[i] == '9') str[i] = char('6');
    }
    
    num = stoll(str);

    if(num==1) {
        cout << "no" << "\n";
        return 0;
    }

    for (int i=2;i<=sqrt(num);i++) {
        if (num % i == 0) {
            cout << "no" << "\n";
            return 0;
        }
    }
    cout << "yes" << "\n";
}
