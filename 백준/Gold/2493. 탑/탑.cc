#include<bits/stdc++.h>

typedef long long ll;
using namespace std;


int N;
ll A[500010];

ll dp[500010];

ll find_idx(ll idx, ll height){
    if (A[idx-1] >= height){
        return idx;
    }else if (idx-1 <= 0) return 0;
    else{
        return find_idx(dp[idx-1], height);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    dp[0] = 0;
    if (A[0] < A[1]) dp[1] = 0;
    else{
        dp[1] = 1;
    }

    for (int i = 2; i < N; i++){
        if (A[i-1] >= A[i]){
            dp[i] = i;
        }else{
            dp[i] = find_idx(i,A[i]);
        }
    }

    for (int i = 0; i < N; i++) cout << dp[i] << " ";

}