#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

string value[2501];
int link[2501];

int getPos(int r, int c) {
    return (r-1) * 50 + c;
}
void init() {
    for (int i=0;i<2501;i++) {
        link[i] = i;
        value[i] = "EMPTY";
    }
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    init();
    
    for (int t=0;t<commands.size();t++) {
        stringstream ss(commands[t]);
        vector<string> vec;
        string token;
        while(ss >> token) vec.push_back(token);
        
        if(vec[0] == "UPDATE") {
            if(vec.size() == 4) {
                int r = stoi(vec[1]), c = stoi(vec[2]);
                int pos = getPos(r, c);
                int parent = link[pos];
                value[parent] = vec[3];
            }
            else if (vec.size() == 3) {
                for (int i=0;i<2501;i++) {
                    if(value[i] == vec[1]) value[i] = vec[2];
                }
            }
        }
        else if(vec[0] == "MERGE") {
            int pos1 = getPos(stoi(vec[1]), stoi(vec[2])), pos2 = getPos(stoi(vec[3]), stoi(vec[4]));
            int parent1 = link[pos1], parent2 = link[pos2];
            if(parent1 != parent2) {
                for(int i=0;i<2501;i++) {
                    if(link[i] == parent2) link[i] = parent1;
                }
                if(value[parent1] == "EMPTY" && value[parent2] != "EMPTY") {
                    value[parent1] = value[parent2]; 
                }
                else {
                    value[parent2] = value[parent1];
                }
            }
        }
        else if(vec[0] == "UNMERGE") {
            int pos = getPos(stoi(vec[1]), stoi(vec[2]));
            int parent = link[pos];
            string val = value[parent];
            for (int i=0;i<2501;i++) {
                if(link[i] == parent) {
                    link[i] = i;
                    value[i] = "EMPTY";
                }
            }
            value[pos] = val;
        }
        else {
            int pos = getPos(stoi(vec[1]), stoi(vec[2]));
            int parent = link[pos];
            answer.push_back(value[parent]);
        }
    }    
    
    return answer;
}