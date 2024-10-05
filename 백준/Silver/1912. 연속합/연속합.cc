#include<bits/stdc++.h>

using namespace std;




int N;

int dp[100001];
int A[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    vector<int> v;

    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    dp[0] = A[0];

    int sum = A[0];

    for (int i = 1; i < N; i++){
        dp[i] = max(dp[i-1] + A[i] , A[i]);
        sum = max(dp[i], sum);
    }

    cout << sum;

}