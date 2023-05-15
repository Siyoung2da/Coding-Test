#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> vec;
    vector<int> result;
    for (int i=0;i<N;i++) {
        vec.push_back(i+1);
    }
    int i = 0;
    while(!vec.empty()) {
        i += K-1;
        i = i % vec.size();
        result.push_back(vec[i]);
        vec.erase(vec.begin() + i);
    }
    cout << "<";
    for (int i=0;i<N-1;i++) {
        cout << result[i] << ", ";
    }
    cout << result[N-1] << ">\n";
}