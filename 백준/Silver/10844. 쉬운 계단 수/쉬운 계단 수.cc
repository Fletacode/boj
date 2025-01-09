#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;

ll dp[110][10]; //i 자리수일때, 마지막 수 j인 경우의 수수
const int DIV = 1e9;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 1; i <= 9; i++){
        dp[1][i] = 1;
    }
    
    for (int i = 2; i <= 100; i++){
        dp[i][0] = dp[i-1][1];
        dp[i][9] = dp[i-1][8];
        for (int j = 1; j < 9; j++){
            dp[i][j] = (dp[i-1][j-1] % DIV) + (dp[i-1][j+1] % DIV);
        }
    }
    
    ll ans = 0;
    for (int i = 0; i <= 9; i++){
        ans += dp[N][i] % DIV;
        
    }
 

    cout << ans % DIV;
}