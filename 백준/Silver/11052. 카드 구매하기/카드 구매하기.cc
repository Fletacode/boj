#include<bits/stdc++.h>

using namespace std;

int n;

int dp[1010];

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> dp[i];
    }

    for (int i =2; i <= n; i++){
        for (int j = i-1; j >= 1; j--){
            dp[i] = max(dp[i],dp[j]+ dp[i-j]);
        }
        
    }

    cout << dp[n];
}