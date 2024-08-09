#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int N;

ll A[100010][3];
ll dp[100010][3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int cnt = 1;

    while(true){
        cin >> N;
        if (N == 0) break;

        for (int i = 0; i < N; i++){
            for (int j = 0; j < 3; j++){
                 A[i][j] = 0;
                dp[i][j] = 1e9;
            }
        }

        for (int i = 0; i < N; i++){
            for (int j = 0; j < 3; j++){
                cin >> A[i][j];
                dp[i][j] = 1e9;
            }
        }

        
        dp[0][1] = A[0][1];
        dp[0][2] = A[0][2] + dp[0][1];

        
        

        for (int i = 1; i < N; i++){
            dp[i][0] = min(dp[i-1][0],dp[i-1][1]) + A[i][0];
            dp[i][1] = min({dp[i-1][0],dp[i][0]
              ,dp[i-1][1],dp[i-1][2]}) + A[i][1];
            dp[i][2] = min({dp[i][1], dp[i-1][1] , dp[i-1][2] }) + A[i][2];
        }


        cout << cnt++ << ". " << dp[N-1][1] << "\n";
    

    }


}