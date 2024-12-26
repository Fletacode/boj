#include<bits/stdc++.h>


using namespace std;

int N;
int dp[1000010];

void go(int depth, int now){


    if (dp[now] < depth) return;

    dp[now] = min(dp[now],depth);

    if (now == 1) return;


    if (now % 2 == 0){
        go(depth + 1, now / 2);
    }

    if (now % 3 == 0){
        go(depth + 1, now / 3);
    }
    
    if (now - 1 > 0){
        go(depth + 1, now -1);
    }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++){
        dp[i] = 1e9;
    }

    go(0,N);

    cout << dp[1];

}