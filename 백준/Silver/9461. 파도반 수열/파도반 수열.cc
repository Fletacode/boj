#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int T,N;

ll dp[110];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    
    
    for (int i = 6; i <= 100; i++){
        
        dp[i] = dp[i-1] + dp[i-5];

    }

    cin >> T;

    while(T--){
        cin >> N;
        cout << dp[N] << "\n";
    }
   
}