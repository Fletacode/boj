#include<bits/stdc++.h>

using namespace std;

int n;

int dp[100010];

int main(){
    cin >> n;
    dp[1] = 3;
    dp[2] = 7;
    for (int i = 3; i <= n; i++){
        dp[i] = ((dp[i-1] * 2) + dp[i-2] ) % 9901;
    }

    cout << dp[n] % 9901;

    
}