#include <iostream>
#include <regex>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t=0;t<T;t++) {
        string str;
        cin >> str;

        regex re("(100+1+|01)+");

        if (regex_match(str, re)) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
}