#include<bits/stdc++.h>

typedef long long ll;

using namespace std;


int N,M;

vector<ll> v;

ll find_low(ll num){

    int st = 0;
    int end = v.size()-1;

    while(st <= end){

        int mid = (st+end) / 2;

        if (v[mid] < num){
            st = mid + 1;
        }else{
            end = mid - 1;
        }

    }

    return st;

}

ll find_upper(ll num){

    int st = 0;
    int end = v.size()-1;

    while(st <= end){

        int mid = (st+end) / 2;

        if (v[mid] > num){
            end = mid - 1;
        }else{
            st = mid + 1;
        }

    }

    return end + 1;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;


    for (int i = 0; i < N; i++){
        ll num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(),v.end());

    
    //cout << find_low(3) << " " << find_upper(3);
    
    
    ll a,b;
    while(M--){
        cin >> a >> b;

        int st = find_low(a);
        int end = find_upper(b);

       

        //cout << st << " " << end << "\n";

        cout << end - st << "\n";
    }
    
    
    

}