#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    bool check = true;
    int maxLong = n-1;
    while(check) {
        int give = 0, get = 0;
        bool once = false;
        for(int i=maxLong;i>=0;i--) {
            give += deliveries[i];
            get += pickups[i];
            if(!once && (give != 0 || get != 0)) {
                maxLong = i;
                answer += (maxLong+1) * 2;
                once = true;
            }
            // cout << "give : " << give << " get : " << get << " i : " << i+1 << " answer : " << answer <<  "\n";
            
            if(give >= cap) {
                deliveries[i] = give - cap;
                // answer += maxLong * 2;
                if(get >= cap) {
                    pickups[i] = get - cap;   
                }
                else {
                    pickups[i] = 0;
                    for (int j=i-1;j>=0;j--) {
                        get += pickups[j];
                        if(get >= cap) {
                            pickups[j] = get - cap;
                            break;
                        }
                        pickups[j] = 0;
                    }
                }
                break;
            }
            else if(get >= cap) { 
                pickups[i] = get - cap;
                // answer += maxLong * 2;
                if(give >= cap) {
                    deliveries[i] = give - cap;   
                }
                else {
                    deliveries[i] = 0;
                    for (int j=i-1;j>=0;j--) {
                        give += deliveries[j];
                        if(give >= cap) {
                            deliveries[j] = give - cap;
                            break;
                        }
                        deliveries[j] = 0;
                    }
                }
                break;
            }
            deliveries[i] = 0;
            pickups[i] = 0;
            if(i==0) {
                if(give == 0 && get == 0)
                    check = false;
            }
        }
    }
    
    return answer;
}