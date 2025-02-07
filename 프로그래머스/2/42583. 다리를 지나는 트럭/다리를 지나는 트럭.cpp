#include <bits/stdc++.h>

using namespace std;


priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; 

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    
    int answer = 0;
     
    //sort(truck_weights.begin(), truck_weights.end());
    
    int time = 0;
    int now_weight = 0;
    int cnt = 0;
    
    for (int i = 0; i < truck_weights.size(); i++){
        int truck = truck_weights[i];
        time += 1;
        
        while(!pq.empty() && pq.top().first == time){
            now_weight -= pq.top().second;
            pq.pop();
            cnt -= 1;
        }
        
        if (cnt < bridge_length && now_weight + truck <= weight) {
            now_weight += truck;
            pq.push({time + bridge_length,truck});
            cnt += 1;
        } else {
            i--;
        }
    }
    
    int ans = 0;
    
    while(!pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();
        ans = max(ans,pq.top().first);
    }
    
    return ans;
}