#include<bits/stdc++.h>


using namespace std;

int N;

int dp[35];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    if (N % 2 != 0){
        cout << 0;
        return 0;
    }

    dp[0] = 1;
    dp[2] = 3;
    dp[4] = 11;

    for (int i = 6; i <= 30; i+=2){
        dp[i] += dp[i-2] * dp[2];
        for (int j = i-4; j >= 0; j-=2){
            dp[i] += dp[j] * 2;
        }
      
    }

    cout << dp[N];
    
    
}