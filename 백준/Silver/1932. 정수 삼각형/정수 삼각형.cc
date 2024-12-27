#include<bits/stdc++.h>


using namespace std;

typedef long long ll;

ll A[510][510];
ll dp[510][510];

int N;






int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    int cnt = 1;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < cnt; j++){
            cin >> A[i][j];
        }   
        cnt++;
    }

    dp[0][0] = A[0][0];

    for (int i = 1; i < N; i++){
        for (int j = 0; j <= i+1; j++){
            if (j == 0){
                dp[i][j] = dp[i-1][j] + A[i][j];
            } else if (j == i+1){
                dp[i][j] = dp[i-1][j-1] + A[i][j];
            } else{
                dp[i][j] = max(dp[i-1][j-1] + A[i][j], dp[i-1][j] + A[i][j]);
            }
        }
    }


    ll ans = 0;
    for (int i = 0; i < N; i++){
        ans = max(ans, dp[N-1][i]);
    }

    cout << ans;

}