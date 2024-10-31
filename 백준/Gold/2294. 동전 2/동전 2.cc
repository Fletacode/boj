#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int dp[10010];



int N,K;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    
    fill(dp,dp+10010,1e9);

    

    dp[0] = 0;

    
    int coin;
    for (int i = 0; i < N; i++){
        cin >> coin;
        for (int j = coin; j <= K; j++){
            dp[j] = min(dp[j], dp[j-coin] + 1);
        }
    }

    if (dp[K] == 1e9){
        cout << -1;
    }else{
         cout << dp[K];
    }
   

}