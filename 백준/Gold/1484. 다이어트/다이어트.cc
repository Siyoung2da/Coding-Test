#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

vector<int> result;

int main() {
    int g;
    cin >> g;

    if (g==1) {
        cout << "-1\n";
        return 0;
    }
    
    int now = sqrt(g);
    int past = now - 1;

    int value = 0;

    while (1)
    {
        if(pow(now, 2) - pow(now-1, 2) > g) break;

        value = pow(now, 2) - pow(past, 2);
        if(value == g) {
            result.push_back(now);
            now++;
            past = now - 1;
            continue;
        }

        if(value < g) {
            past--;
            if(past <= 0) {
                now++;
                past = now - 1;
                continue;
            } 
        }

        if(value > g) {
            now++;
            past = now - 1;
            continue;
        }    
    }
    if(result.size() == 0) cout << "-1\n";
    else {
        for (int i=0;i<result.size();i++)
            cout << result[i] << "\n";
    }
}