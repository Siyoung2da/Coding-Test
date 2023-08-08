#include <iostream>
#include <string>
using namespace std;

int n;
string result;
bool visit;
void dfs(string s, int cnt)
{
    if (visit)
        return;
    int size = s.size();
    for (int i = 1; i <= size / 2; i++)
    {
        if (s.substr(size - i, i) == s.substr(size - 2 * i, i))
        {
            return;
        }
    }
    if (cnt == n)
    {
        result = s;
        visit = true;
    }
    for (int i = 0; i < n; i++)
    {
        dfs(s + "1", cnt + 1);
        dfs(s + "2", cnt + 1);
        dfs(s + "3", cnt + 1);
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    dfs("", 0);
    cout << result << "\n";
}