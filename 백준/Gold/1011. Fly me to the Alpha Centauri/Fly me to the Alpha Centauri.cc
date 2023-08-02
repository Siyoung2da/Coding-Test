#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int move(long long x, long long y);
int main() {
   int T;
   long long a, b;

   cin >> T;
   int *arr = new int[T];
   for (int i=0;i<T;i++) {
      cin >> a >> b;
      arr[i] = move(a, b);
   }
   for (int i=0;i<T;i++) {
      cout << arr[i] << endl;
   }
   delete [] arr;
}
int move(long long x, long long y) {
   long long max=1;
   while (1) {
      if(max*max <= (y-x) && (max+1)*(max+1) > (y-x))
         break;
      max++;
   }
   if((y-x) > max*max && (y-x) <= max*max + max)
      return max*2;
   else if((y-x) < (max+1)*(max+1) && (y-x) >= max*max + max)
      return max*2+1;
   else
      return max*2-1;
}