#include<bits/stdc++.h>


using namespace std;
typedef long long ll;


int N,K;

ll dp[210][210];
const ll DIV = 1000000000;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;

    for (int i = 1; i <= 200; i++){
        dp[i][1] = 1;
        dp[1][i] = i;
    }

    for (int i = 2; i <= 200; i++){
        for (int j = 2; j <= 200; j++){
            dp[i][j] = (dp[i][j-1] % DIV) + (dp[i-1][j] % DIV);
        }
    }

    cout << dp[N][K] % DIV;
    

}