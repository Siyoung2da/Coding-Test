#include <iostream>
using namespace std;

int main() {
    
    int x;
    cin >> x;

    int i = 0;
    while (x>0) {
        ++i;
        x = x - i;
    }
    
    if (i%2 == 0) 
        cout << i + x << "/" << 1 - x << "\n"; 
    else
        cout << 1 - x << "/" << i + x << "\n";

}
