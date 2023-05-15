#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ERR 1e-13

int main()
{
    int N, K;
    cin >> N >> K;

    vector<double> vec;
    for (int i = 0; i < N; i++)
    {
        double num;
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end());

    double trimmed = 0.0;
    for (int i = K; i < N - K; ++i)
        trimmed += vec[i];
    trimmed /= (N - 2 * K);

    cout.precision(2);
    cout << fixed;
    cout << trimmed + ERR << "\n";

    double adjusted = vec[K] * K + vec[N - K - 1] * K;
    for (int i = K; i < N - K; ++i)
        adjusted += vec[i];
    adjusted /= N;

    cout.precision(2);
    cout << fixed;
    cout << adjusted + ERR << "\n";

    return 0;
}
