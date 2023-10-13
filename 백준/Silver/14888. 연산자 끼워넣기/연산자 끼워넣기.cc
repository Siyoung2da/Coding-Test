#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
long long a[12];
int op[4];
long long maxValue, minValue;
bool first;

long long calculate(long long num, int index, int d) {
    if(d==0) {
        return num + a[index];
    }
    else if(d==1) {
        return num - a[index];
    }
    else if(d==2) {
        return num * a[index];
    }
    else {
        return num / a[index];
    }
}

void dfs(long long num, int index) {
    if(index == n) {
        maxValue = max(maxValue, num);
        minValue = min(minValue, num);

        if(!first) {
            if(maxValue > 0)
                minValue = maxValue;
            else if(minValue < 0)
                maxValue = minValue;
            first = true;
        }

        return;
    }    

    for(int i=0;i<4;i++) {
        if(op[i] != 0) {
            op[i]--;
            long long newNum = calculate(num, index, i);
            // cout << newNum << " " << i << "\n";
            dfs(newNum, index + 1);
            op[i]++;
        }

    }
    
}

int main() {
    cin >> n;
    for (int i=0;i<n;i++) 
        cin >> a[i];
    
    for (int i=0;i<4;i++) {
        cin >> op[i];
    }

    dfs(a[0], 1);
    cout << maxValue << "\n" << minValue << "\n";
}