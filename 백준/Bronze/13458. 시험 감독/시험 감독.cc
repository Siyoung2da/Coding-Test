#include <iostream>
#include <vector>

using namespace std;

long long n, b, c;
vector<long long> vec;

int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        long long num;
        cin >> num;
        vec.push_back(num);
    }
    cin >> b >> c;
    
    long long result = vec.size();

    for(int i=0;i<vec.size();i++) {
        vec[i] = vec[i] - b;
        if(vec[i] <= 0) {
            continue;
        }
        else if(vec[i] % c == 0) {
            result += vec[i]/c;
        }
        else if(vec[i] % c != 0) {
            if(vec[i] / c == 0) result++;
            else {
                result += vec[i] / c + 1;
            }
        }
    }
    cout << result << "\n";
}