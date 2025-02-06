#include <bits/stdc++.h>

using namespace std;

int cal_day(int pro, int speed){
    
    if ((100 - pro) % speed > 0){
         return ((100 - pro) / speed) + 1;
    } else {
         return (100 - pro) / speed;
    }
   
    
}


vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> ans;
    
    int max_day = cal_day(progresses[0], speeds[0]);
    int cnt = 1;
    int day = 0;
    
    for (int i = 1; i < progresses.size(); i++) {
        
        day = cal_day(progresses[i], speeds[i]);
        
        if (max_day < day) {
            ans.push_back(cnt);
            max_day = day;
            cnt = 0;
        }
        
        cnt += 1;
    }
    
    ans.push_back(cnt);
    
    return ans;
}