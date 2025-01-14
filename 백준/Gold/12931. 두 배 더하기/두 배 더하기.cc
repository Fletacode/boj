#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;

int B[1010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> B[i];
    }

    ll ans1 = 0;
    ll ans2 = 0;

    for (int i = 0; i < N; i++){
        ll cnt = 0;
        
        while (B[i] > 0){
            if (B[i] == 1) {
                ans2 += 1;
            } else if (B[i] % 2 != 0){
                cnt += 1;
                ans2 += 1;
            } else {
                cnt += 1;
            }
            B[i] /= 2;
        }

        ans1 = max(ans1, cnt);
    }

    cout << ans1 + ans2;
    

}