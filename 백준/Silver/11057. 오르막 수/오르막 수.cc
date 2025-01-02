#include<bits/stdc++.h>


using namespace std;

int dp[1010][10];
//x 자리일때, 뒷의 숫자수 ex) 1 2 1자리일때, 맨 뒤의 숫자 2

int N;
const int DIV = 10007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i <= 9; i++){
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; i++){
        for (int j = 0; j <= 9; j++){
            
            
            for (int k = 0; k <= j; k++){
                dp[i][j] += dp[i-1][k] % DIV;
            }

            
        }
    }

    //calculate ans
    int ans = 0;
    for (int i = 0; i <= 9; i++){
        ans += dp[N][i] % DIV;
    }

    cout << ans % DIV;


}