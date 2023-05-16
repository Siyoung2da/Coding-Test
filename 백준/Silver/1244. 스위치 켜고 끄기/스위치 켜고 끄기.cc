#include <iostream>
using namespace std;

int main() {
    int switches[101];
    int switchNum;
    cin >> switchNum;

    for (int i=1;i<=switchNum;i++) {
        cin >> switches[i];
    }

    int student;
    cin >> student;
    for(int i=0;i<student;i++) {
        int sex, whatSwitch;
        cin >> sex >> whatSwitch;
        if(sex == 1) {
            for (int j=whatSwitch;j<=switchNum;j+=whatSwitch) {
                if (switches[j] == 1) {
                    switches[j] = 0;
                }
                else {
                    switches[j] = 1;
                }
            }
        }
        else {
            if (switches[whatSwitch] == 1) {
                switches[whatSwitch] = 0;
            }
            else {
                switches[whatSwitch] = 1;
            }
            for (int j=1;switches[whatSwitch - j] == switches[whatSwitch + j];j++) {
                if(whatSwitch - j < 1 || whatSwitch + j > switchNum) {
                    break;
                }
                if (switches[whatSwitch - j] == 1) {
                    switches[whatSwitch - j] = 0;
                }
                else {
                    switches[whatSwitch - j] = 1;
                }
                if (switches[whatSwitch + j] == 1) {
                    switches[whatSwitch + j] = 0;
                }
                else {
                    switches[whatSwitch + j] = 1;
                }
            }
        }
        
    }
    for (int i=1;i<switchNum;i++) { 
        if(i % 20 == 0) {
            cout << switches[i];
            cout << "\n";
        }
        else {
            cout << switches[i] << " ";
        }
    }
    cout << switches[switchNum];
}