#include<bits/stdc++.h>


using namespace std;

typedef long long ll;

int N;

int dp[1010][4];
int arr[1010][4];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= 3; j++){
            cin >> arr[i][j];
            dp[i][j] = 1e9;
        }
    }

    dp[1][1] = arr[1][1];
    dp[1][2] = arr[1][2];
    dp[1][3] = arr[1][3];

    for (int i = 2; i <= N; i++){
        
            
        dp[i][1] = min(arr[i][1] + dp[i-1][2], arr[i][1] + dp[i-1][3]);
        dp[i][2] = min(arr[i][2] + dp[i-1][1], arr[i][2] + dp[i-1][3]);
        dp[i][3] = min(arr[i][3] + dp[i-1][1], arr[i][3] + dp[i-1][2]);
            
    }

    cout << min(dp[N][1], min(dp[N][2], dp[N][3]));


}