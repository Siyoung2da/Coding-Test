#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
using namespace std;

deque<string> split(string str, char Delimiter) {
    istringstream iss(str);             // istringstream에 str을 담는다.
    string buffer;                      // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼
 
    deque<string> result;
 
    // istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);               // 절삭된 문자열을 vector에 저장
    }
 
    return result;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int n;
        string fc, num;

        cin >> fc >> n >> num;
        
        vector<char> fun;
        for(int i=0;i<fc.length();i++) {
            fun.push_back(fc[i]);
        }

        num.erase(num.begin());
        num.erase(num.end()-1);
        
        deque<string> number = split(num, ',');
        
        int rcnt = 0, dcnt = 0, error = 0;
        for(int i=0;i<fun.size();i++) {
            if(fun[i]=='R') {
                rcnt++;
            }
            else {  // fun[i]=='D'
                if(number.empty()) {
                    cout << "error" << "\n";
                    error++;
                    break;
                }
                if(rcnt%2 == 0) {
                    number.pop_front();
                }
                else if (rcnt%2 == 1) {
                    number.pop_back();
                }    
            }
        }
        if(error!=0) {
            continue;
        }
        else {
            cout << "[";
            if(rcnt%2==0) {
                for(int i=0;i<number.size();i++) {
                    if(i<number.size()-1)
                        cout << number[i] << ",";
                    else   cout << number[i];
                }
            }
            else {
                for(int i=number.size()-1;i>=0;i--) {
                    if(i>0)
                        cout << number[i] << ",";
                    else   cout << number[i];
                }
            }
            cout << "]" << "\n";
        }

    }
}