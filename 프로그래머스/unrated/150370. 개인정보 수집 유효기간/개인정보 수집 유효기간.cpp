#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    int nowYear = stoi(today.substr(0, 4));
    int nowMonth = stoi(today.substr(5, 2));
    int nowDay = stoi(today.substr(8, 2));
    
    for (int i=0;i<privacies.size();i++) {
        char type = privacies[i][privacies[i].size()-1];
        int strYear = stoi(privacies[i].substr(0, 4));
        int strMonth = stoi(privacies[i].substr(5, 2));
        int strDay = stoi(privacies[i].substr(8, 2));
        
        for(int j=0;j<terms.size();j++) {
            if(type == terms[j][0]) {
                int plus = stoi(terms[j].substr(2));
                strMonth += plus;
                if(strMonth > 12) {
                    strYear += strMonth / 12;
                    strMonth %= 12;
                    if(strMonth == 0) {
                        strYear -= 1;
                        strMonth = 12;
                    }
                }
                break;
            }
        }
        if(strYear < nowYear) {
            answer.push_back(i+1);
        }
        else if(strYear == nowYear) {   
            if(strMonth < nowMonth) {
                answer.push_back(i+1);
            }
            else if(strMonth == nowMonth) {
                if(strDay - 1 < nowDay) {
                    answer.push_back(i+1);
                }
            }
        }
    }
    
    return answer;
}