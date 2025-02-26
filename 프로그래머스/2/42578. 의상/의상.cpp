#include <bits/stdc++.h>

using namespace std;

map<string,int> mp;

int solution(vector<vector<string>> clothes) {
    int ans = 1;
    
    for (int i = 0; i < clothes.size(); i++) {
        mp[clothes[i][1]] = mp[clothes[i][1]] + 1;
    }
    
    for (auto iter : mp) {
        ans *= iter.second + 1;
    }
    
    ans -= 1;
    
    return ans;
}