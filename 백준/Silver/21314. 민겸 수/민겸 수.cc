#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    cin >> str;

    string big = "";
    string small = "";

    int mCount = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'M')
        {
            mCount++;
        }
        if (str[i] == 'K')
        {
            if (mCount >= 1)
            {
                small += '1';
            }
            big += '5';
            for (int j = 0; j < mCount; j++)
            {
                big += '0';
            }
            for (int j = 1; j < mCount; j++)
            {
                small += '0';
            }
            small += '5';
            mCount = 0;
        }
    }
    if(mCount > 0) {
        small += '1';
        for (int i=1;i<mCount;i++) small += '0';
        for (int i=0;i<mCount;i++) big += '1';
    }
    cout << big << "\n" << small << "\n";
}