#include<bits/stdc++.h>

using namespace std;

int N;

int DIV = 10007;

int dp[1010];

int main(){
    cin >> N;

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= N; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % DIV;
    }

    cout << dp[N] % DIV;
}