#include<bits/stdc++.h>

typedef long long ll;

using namespace std;


ll N,Q;

ll A[100010];
ll T[100010 * 4];

ll init(int node,int st ,int end){
    if (st == end){
        return T[node] = A[st];
    }

    ll mid = (st+end) / 2;

    ll leftTree = init(node * 2, st, mid);
    ll rightTree = init(node*2 + 1, mid+1, end);

    return T[node] =  leftTree + rightTree;


}

ll sum(int node, int st, int end, int left ,int right){
    if (end < left || right < st) return 0;

    if (left <= st && end <= right) return T[node];

    ll mid = (st+end) /2;

    ll leftTree = sum(node*2,st,mid, left, right );
    ll rightTree = sum(node*2+1, mid+1, end, left, right);

    return leftTree + rightTree;


}

void updateTree(int node ,int st, int end, int idx,ll val){

    if (idx  < st || idx > end) return;

    

    if (idx >= st && idx <= end) {
        T[node] += val;
    }

    ll mid = (st+end) /2;


    if (st != end){
        updateTree(node*2, st,mid,idx,val);
        updateTree(node*2 + 1, mid+1, end, idx,val);
    
    }
    

    
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> Q;


    for (int i = 0; i < N; i++) cin >> A[i];

    init(1,0,N-1);

    //for (int i = 1; i < N*4; i++) cout << T[i] << " ";

    
    ll x,y,a,b;
    for (int i = 0; i < Q; i++){
        cin >> x >> y >> a >> b;
        
        if (x > y){
            ll temp = y;
            y = x;
            x = temp;
        }

        cout << sum(1,0,N-1,x-1,y-1) << "\n";

        //cout << "b:" << b << "A[a-1]:" << A[a-1] << "\n";

        ll val = b - A[a-1];
        A[a-1] = b;

        //cout << val << "\n";

        //for (int i = 1; i < N*4; i++) cout << T[i] << " ";

        //cout << "\n";

        updateTree(1,0,N-1,a-1,val);

        //for (int i = 1; i < N*4; i++) cout << T[i] << " ";

        //cout << "\n";

    }
    


}