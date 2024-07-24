#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<pair <int, pair<int,int> > > v;



int N;



ll cal(int a, int b,int c, int d,int p){
    return max(0,p - (abs(a-c) + abs(b-d) ));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    
    int x,y,e;
    for (int i = 0; i <= N; i++){
        cin >> x >> y >> e;
        v.push_back({e,{x,y}});
    }

    ll ans = -1;

    ll py = v[0].second.second;
    ll px = v[0].second.first;
    ll pval = v[0].first;

    for (int i = 1; i <= N; i++){
        ll nry = v[i].second.second;
        ll nrx = v[i].second.first;
        ll nre = v[i].first;
        ll val = cal(px,py,nrx,nry, pval );
        for (int j = 1; j <= N; j++){
            ll nry2 = v[j].second.second;
            ll nrx2 = v[j].second.first;
            ll nre2 = v[j].first;
            val -= cal(nrx,nry,nrx2, nry2, nre2);
        }
        if (val <= 0) continue;

        ans = max(ans,val);
    }
    
    if (ans == -1) cout << "IMPOSSIBLE";
    else{
        cout << ans;
    }
    

    
    

}