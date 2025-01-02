#include<bits/stdc++.h>


using namespace std;

int N;
int dp[1000010];

const int DIV = 15746;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 5;

    for (int i = 5; i <= N; i++){
        dp[i] = (dp[i-1] % DIV) + (dp[i-2] % DIV);
    }

    cout << dp[N] % DIV << "\n";

}