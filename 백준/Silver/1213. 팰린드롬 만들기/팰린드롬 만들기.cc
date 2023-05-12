#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int alphaCount[26];
int countOdd;
char Odd;
string result;

bool isPelindrom(string str) {
    for (int i=0;i<str.size();i++) {
        alphaCount[(int)str[i] - 65]++;
    }
    for (int i=0;i<26;++i) {
        if(alphaCount[i] % 2 == 1) {
            Odd = char(i + 65);
            countOdd++;
            if(alphaCount[i] != 1) {
                for(int j=0;j<alphaCount[i]/2;j++) {
                    result += char(i + 65);
                }
            }
        }
        else {
            for(int j=0;j<alphaCount[i]/2;j++) {
                result += char(i + 65);
            }
        }
        if(countOdd > 1) {
            return false;
        }        
    }
    return true;
}

int main() {
    string str;
    cin >> str;
    sort(str.begin(), str.end());
    
    if(!isPelindrom(str)) cout << "I'm Sorry Hansoo";
    else {
        string front = result;
        reverse(result.begin(), result.end());
        if(countOdd == 1) {
            cout << front;
            cout << Odd;
            cout << result << "\n";
        }
        else {
            cout << front;
            cout << result << "\n";
        }
    }
}