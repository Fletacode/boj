#include <bits/stdc++.h>


#define MOD 1000000007

typedef long long ll;

using namespace std;

int main() {
    ll n, m, a, b, c, ans = 1;
    
    cin >> n >> m;

    a = n*m;

    if(n < 3 && m < 3) {
        cout << n*m;
        return 0;
    }
    b = a/3;
    c = a%3;
    if(c == 1) b--;
    while(b--){
        ans *= 3;
        ans %= MOD;
    }
    if(c==1) ans *= 4;
    if(c==2) ans *= 2;
    cout << ans%MOD;
}