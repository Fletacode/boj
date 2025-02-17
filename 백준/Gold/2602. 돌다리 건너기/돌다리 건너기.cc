#include<bits/stdc++.h>


using namespace std;

string ans_road;

string road[2];

int dp[25][110][2];

int go(int ans_idx,int now_idx, bool road_idx) {

    if (ans_idx == ans_road.size()){
        return 1;
    }

    if (dp[ans_idx][now_idx][road_idx] != 0) return dp[ans_idx][now_idx][road_idx];

    int cnt = 0;

    for (int i = now_idx; i < road[0].size(); i++) {
        if (road[road_idx][i] == ans_road[ans_idx]) {
            cnt += go(ans_idx + 1, i + 1, !road_idx);
        }
    }

    return dp[ans_idx][now_idx][road_idx] = cnt;
}


int main() {
    cin >> ans_road >> road[0] >> road[1];

   

    cout <<  go(0,0,0) + go(0,0,1);
}