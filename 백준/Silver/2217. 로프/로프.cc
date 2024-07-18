#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int N;

ll max_val = -1;
vector<ll> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

   cin >> N;


   ll num;
   for (int i = 0; i < N; i++){
    cin >> num;
    v.push_back(num);
   }

   sort(v.begin(),v.end());


    for (int i = 0; i < N; i++){
        max_val = max(max_val,v[i]* (N-i) );
    }

    cout << max_val;
   


}