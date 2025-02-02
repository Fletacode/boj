#include<bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef __int128 lll;

ll N,ans;

void cal(ll first, ll next) {

    ll d = next - first;

    lll val = first * 10 + next;

    while(val <= N){
        ans++;
        next += d;

        if (next < 0 || next > 9) break;

        val = val * 10 + next;
    } 

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 1; i < 10; i++){
        if (i <= N) ans++;
        for (int j = 0; j < 10; j++) {
            cal(i,j);
        }
    }


    cout << ans;
}