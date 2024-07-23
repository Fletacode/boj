#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int N;
ll A[100010];
int M;

ll T[100010 * 4];

void update(int node, int st, int end, int idx, ll val){

    if (st == end){
        T[node] = val;
        return;
    }

    ll mid = (st+end) / 2;

    if (idx <= mid) update(node*2, st, mid, idx,val);
    else{
        update(node*2+1, mid + 1, end, idx,val);
    }

    T[node] = min(T[node*2] , T[node*2 + 1]);

}

ll min_cal(int node, int st, int end, int left , int right){

    if (left > end || right < st) return 1e9 + 10;

    if (left <= st && end <= right) return T[node];

    ll mid = (st+end) / 2;

    ll left_tree = min_cal(node*2,st, mid, left, right );
    ll right_tree = min_cal(node*2 + 1, mid+ 1, end, left, right);

    return min(left_tree , right_tree);

}

ll init(int node, int st, int end){
    if (st == end){
        return T[node] = A[st];
    }

    ll mid = (st+end) / 2;

    ll left_tree = init(node*2,st, mid);
    ll right_tree = init(node*2 + 1, mid+ 1, end);

    return T[node] =  min(left_tree, right_tree);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    init(1, 0 , N-1);

    //for (int i = 1; i <= N*4; i++) cout << T[i] << " ";
    //cout << "\n";

    cin >> M;

    ll a,b,c;
    while(M--){
        cin >> a;
        if (a == 1){
            cin >> b >> c;
            A[b-1] = c;
            update(1,0, N-1, b-1, c);
        }else{
            cin >> b >> c;
            cout << min_cal(1, 0, N-1, b-1,c-1) << "\n";
        }
    }

}