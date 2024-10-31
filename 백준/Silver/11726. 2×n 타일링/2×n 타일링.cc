#include<bits/stdc++.h>


using namespace std;

int N;

int MOD = 10007;

int dp[1010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= N; i++){
        dp[i] = (dp[i-1] % MOD) + (dp[i-2] % MOD);
    }


    cout << dp[N] % MOD;
}