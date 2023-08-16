#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string makeBin(long long num) {
    string str = "";
    while(num > 0) {
        str = to_string(num % 2) + str;
        num /= 2;
    }
    
    int len = 1;
    while(len <= str.length()) {
        len *= 2;
    }
    len -= 1;
    
    while(len > str.length()) {
        str = '0' + str;
    }
    return str;
}

int isOkay(string str) {
    int middle = str.length() / 2;
    
    string leftStr = str.substr(0, middle);
    string rightStr = str.substr(middle+1);
    
    bool flag = true;
    for(int i=0;i<str.length();i++) {
        if(str[i] == '1') {
            flag = false;
            break;
        }
    }
    if(flag || str.length() == 1) return 1;
    
    if(str[middle] == '1' && isOkay(leftStr) && isOkay(rightStr)) {
        return 1;
    }
    else return 0;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(int i=0;i<numbers.size();i++) {
        long long num = numbers[i];
        
        string str = makeBin(num);
        
        answer.push_back(isOkay(str));
        
    }
    
    return answer;
}

// 7 : 1 1 1
// 42 : 0 1 0 1 0 1 0
// 63 : 0 1 1 1 1 1 1
// 111 : 1 1 0 1 1 1 1