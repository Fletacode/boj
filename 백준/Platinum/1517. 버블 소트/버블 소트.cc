#include<bits/stdc++.h>


typedef long long ll;

using namespace std;

vector<pair<ll,ll> > v; //val idx

ll T[500010 * 4];

ll N;

void update_tree(int node,int st,int end,int idx){

    if (idx < st || idx > end) return;

    if (st == end) {
        T[node] = 1;
        return;
    }
    

    ll mid = (st+end) / 2;

    update_tree(node*2, st,mid,idx);
    update_tree(node*2 + 1,mid+1,end,idx);
    
    T[node] = T[node*2] + T[node*2+1];

}


ll find_cnt(int node,int st, int end, int left, int right){

    if (end < left || right < st) return 0;

    if (left <= st && end <= right) return T[node];

    ll mid = (st+end) / 2;

    ll leftTree = find_cnt(node*2, st , mid, left, right);
    ll rightTree =  find_cnt(node*2+1, mid + 1, end, left, right);
    return  leftTree + rightTree;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    ll val;
    for (int i = 0; i < N; i++){
        cin >> val;
        v.push_back({val,i});
    }

    sort(v.begin(),v.end());

    ll ans = 0;

    for (int i = 0; i < N; i++){
        
        ans += find_cnt(1,0,N-1,v[i].second,N-1);
        update_tree(1,0,N-1,v[i].second);
    }

    //for (int i = 1; i <= N*4; i++) cout << T[i] << " ";

    cout  << ans;

}