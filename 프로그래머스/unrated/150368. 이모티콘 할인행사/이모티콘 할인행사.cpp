#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int emo, user;
int percent[4] = {10, 20, 30, 40};
vector<int> vec;

void dfs(vector<vector<int>> users, vector<int> emoticons) {
    if(vec.size() == emoticons.size()) {
        int nowEmo = 0;
        int nowUser = 0;
        
        for(int i=0;i<users.size();i++) {
            int howMuch = 0;
            for (int j=0;j<emoticons.size();j++) {
                if(users[i][0] <= vec[j]) {
                    howMuch += emoticons[j] / 100 * (100 - vec[j]);
                }
            }
            if(howMuch >= users[i][1]) nowUser++;
            else nowEmo += howMuch;
        }
        if(nowUser > user) {
            user = nowUser;
            emo = nowEmo;
        }
        else if(nowUser == user) {
            emo = max(emo, nowEmo);
        }
        return;
    }
    for(int i=0;i<4;i++) {
        vec.push_back(percent[i]);
        dfs(users, emoticons);
        vec.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    dfs(users, emoticons);
    answer.push_back(user);
    answer.push_back(emo);
    
    return answer;
}