#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int N;

vector<ll> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    ll num;
    for (int i = 0; i  <N; i++){
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    int i = 0;
    int j = v.size()-1;

    ll sum = abs(v[i] + v[j]);
    ll ans = sum;

    pair<ll,ll> ans_p = {v[i],v[j]};

    while(i < j){
        
        if (abs(v[i] + v[j]) < ans){
            ans = abs(v[i] + v[j]);
            ans_p = {v[i],v[j]};
        }

        if (v[i] + v[j] > 0){
            j--;
        }else{
            i++;
        }

        

    }


    cout << ans_p.first << " " << ans_p.second;
    

}