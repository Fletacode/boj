#include<bits/stdc++.h>

using namespace std;

int T,K;

int dp[510][510];
int cost[510];
int range[510][510];
int sum[510];
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;

    while(T--){
        cin >> K;
        for (int i = 1; i <= K; i++){
            cin >> cost[i];
            sum[i] = cost[i] + sum[i-1];
        }

        for (int i = 1; i <= K; i++){
            range[i-1][i] = i;
        }

        for (int d = 2; d <= K; d++){
            for (int st = 0; st+d <= K; st++){
                int end = st+d;
                dp[st][end] = 1e9;

                for (int mid = range[st][end-1]; mid <= range[st+1][end]; mid++){

                    int val = dp[st][mid] + dp[mid][end] + sum[end] - sum[st];
                    if (dp[st][end] > val){
                        dp[st][end] = val;
                        range[st][end] = mid;
                    }
                }

            }
        }

        cout << dp[0][K] << "\n";



    }

}