#include<bits/stdc++.h>


using namespace std;

int t;
int k;

int dp[510][510];
int A[510];
int sum[510];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while(t--){
        memset(dp,0,510*510);
        memset(A, 0, sizeof(A));
        memset(sum, 0, sizeof(sum));

        cin >> k;
        int num;
        for (int i = 1; i <= k; i++){
            cin >> num;
            sum[i] = num + sum[i-1];
        }

        for (int d = 1; d < k; d++){
            for (int st = 1; st+d <= k; st++){
                int end = st + d;
                dp[st][end] = 1e9;

                for (int mid = st; mid < end; mid++){
                    dp[st][end] = 
                        min(dp[st][end], dp[st][mid] +
                         dp[mid+1][end] + sum[end] - sum[st-1]);
                }

            }
        }

        cout << dp[1][k] << "\n";

    }

}