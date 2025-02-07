#include <bits/stdc++.h>

using namespace std;

queue<pair<int,int>> q;
bool visited[110];
int A[110];

int find_next(int n){
    
    int max_val = -1;
    
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        max_val = max(max_val, A[i]);
    }
    return max_val;   
}


int solution(vector<int> priorities, int location) {
    
    int max_val = 0;
    
    for (int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i],i});
        max_val = max(max_val, priorities[i]);
        A[i] = priorities[i];
    }
    
    int cnt = 0;
    while(true){
        
        if (q.front().first < max_val){
            pair<int,int> temp = q.front();
            q.pop();
            q.push(temp);
        } else {
            pair<int,int> temp = q.front();
            q.pop();
            
            if (temp.second == location) {
                cnt++;
                break;
            }
            
            visited[temp.second] = true;
            max_val = find_next(priorities.size());
            cnt++;
        }
        
    }
    
    
    return cnt;
}