#include<bits/stdc++.h>


using namespace std;
typedef long long ll;

ll n,k;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    ll st = 0;
    ll end = n / 2;
    bool flag = false;

    while(st <= end){
        int mid = (st+end) / 2;
        if ((mid+1) * (n - mid + 1) > k) {
            end = mid - 1;
        } else if ((mid+1) * (n - mid + 1) < k) {
            st = mid + 1;
        } else {
            flag = true;
            break;
        }
    }

    //cout << st << "\n";

    if (flag){
        cout << "YES";
    } else {
        cout << "NO";
    }
   
    

}