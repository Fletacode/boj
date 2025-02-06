#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int ans = 1;

map<string,int> Map;

vector<int> v;

void make_map(vector<vector<string>> &clothes){
    
    for (int i = 0; i < clothes.size(); i++) {
        
        Map[clothes[i][1]] += 1;
        
    }
    
    for (auto iter = Map.begin(); iter != Map.end(); iter++) {
        v.push_back((*iter).second);
        //cout << (*iter).second;
    }
    
}

void print_v(){
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}


int solution(vector<vector<string>> clothes) {
    
    make_map(clothes);
    
    for (int i = 0; i < v.size(); i++){
        ans *= (v[i] + 1);
    }
    
    ans -= 1;
    
    return ans;
}