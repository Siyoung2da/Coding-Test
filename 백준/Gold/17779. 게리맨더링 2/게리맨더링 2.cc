#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int map[21][21];
int area[21][21];
vector<int> numArea(6);
int minDiff = 99999999;

void areaClear()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            area[i][j] = 0;
        }
    }
    for(int i=0;i<=5;i++) {
        numArea[i] = 0;
    }
}

// 다음 칸은 경계선이다.
// (x, y), (x+1, y-1), ..., (x+d1, y-d1)
// (x, y), (x+1, y+1), ..., (x+d2, y+d2)
// (x+d1, y-d1), (x+d1+1, y-d1+1), ... (x+d1+d2, y-d1+d2)
// (x+d2, y+d2), (x+d2+1, y+d2-1), ..., (x+d2+d1, y+d2-d1)

// 1번 선거구: 1 ≤ r < x+d1, 1 ≤ c ≤ y
// 2번 선거구: 1 ≤ r ≤ x+d2, y < c ≤ N
// 3번 선거구: x+d1 ≤ r ≤ N, 1 ≤ c < y-d1+d2
// 4번 선거구: x+d2 < r ≤ N, y-d1+d2 ≤ c ≤ N

void makeArea(int x, int y, int d1, int d2)
{
    int colStart = y;
    int colEnd = y;
    bool flag1 = false;
    bool flag2 = false;
    for (int r = x; r <= x + d1 + d2; r++)
    {
        for (int c = colStart; c <= colEnd; c++) {
            area[r][c] = 5;
        }
        if(!flag1 && colStart >= y-d1) colStart--;
        if(flag1) colStart++;
        if(colStart == y-d1) flag1 = true;
        
        if(!flag2 && colEnd <= y+d2) colEnd++;
        if(flag2) colEnd--;
        if(colEnd == y+d2) flag2 = true;
    }

    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= n; c++)
        {
            if (area[r][c] == 0)
            {
                if (1 <= r && r < x + d1 && 1 <= c && c <= y)
                {
                    area[r][c] = 1;
                }
                else if (1 <= r && r <= x + d2 && y < c && c <= n)
                {
                    area[r][c] = 2;
                }
                else if (x + d1 <= r && r <= n && 1 <= c && c < y - d1 + d2)
                {
                    area[r][c] = 3;
                }
                else if (x + d2 < r && r <= n && y - d1 + d2 <= c && c <= n)
                {
                    area[r][c] = 4;
                }
            }
        }
    }
}

void countArea() {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            int where = area[i][j];
            numArea[where]+=map[i][j];
        }
    }
    sort(numArea.begin(), numArea.end());
    int diff = numArea[5] - numArea[1];
    minDiff = min(minDiff, diff);
    areaClear();
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
        }
    }
//  d1, d2 ≥ 1, 1 ≤ x < x+d1+d2 ≤ N, 1 ≤ y-d1 < y < y+d2 ≤ N

    for(int x=2;x<=n-1;x++) {
        for(int y=2;y<=n-1;y++) {
            int d1 = 1, d2 = 1;
            while(x + d1 + d2 <= n && y - d1 >= 1 && y + d2 <= n) {
                while(x + d1 + d2 <= n && y - d1 >= 1 && y + d2 <= n) {
                    makeArea(x, y, d1, d2);
                    countArea();

                    d2++;
                }
                d1++;
                d2=1;
            }
        }
    } 
    cout << minDiff << "\n";
}