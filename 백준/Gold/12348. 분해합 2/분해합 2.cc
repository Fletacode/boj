#include<bits/stdc++.h>


using namespace std;
typedef long long ll;

ll N;
string str;

bool check(ll num, ll target) {

    ll sum = 0;

    while(num != 0) {
        //if (num % 10 == 0) return false;
        sum += num % 10;
        num /= 10;
    }

    if (target == sum) {
        return true;
    } else {
        return false;
    }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    cin >> str;
    N = stoll(str);

    ll max_val = min(N,(ll)str.size() * 9);

    for (int i = max_val; i >= 1; i--){

        ll tempN = N - i;

        if (check(tempN,i) ){
            cout << tempN;
            return 0;
        }

    }

    cout << 0;

}