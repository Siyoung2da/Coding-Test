#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    string S, E, Q;
    cin >> S >> E >> Q;

    S.erase(S.begin() + 2);
    int Stime = stoi(S);

    E.erase(E.begin() + 2);
    int Etime = stoi(E);

    Q.erase(Q.begin() + 2);
    int Qtime = stoi(Q);

    set<string> names;
    set<string> attendance;
    while (1)
    {
        string time, name;
        cin >> time >> name;
        if (time == "" && name == "") break;
        time.erase(time.begin() + 2);
        int Ttime = stoi(time);
        if (Ttime <= Stime)
        {
            names.insert(name);
        }
        if (Ttime >= Etime && Ttime <= Qtime)
        {
            if (names.find(name) != names.end())
            {
                attendance.insert(name);
            }
        }
    }
    cout << attendance.size() << "\n";
}