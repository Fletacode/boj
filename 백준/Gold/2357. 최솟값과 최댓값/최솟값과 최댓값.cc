#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int N,M;

ll A[100010];
ll T_max[100010 * 4];
ll T_min[100010 * 4];

ll max_init(int node,int st,int end){
    if (st == end) return T_max[node] = A[st];

    ll mid = (st+end) / 2;

    return T_max[node] = max(max_init(node*2,st,mid) , max_init(node*2+1, mid+1, end));

}

ll min_init(int node,int st,int end){
    if (st == end) return T_min[node] = A[st];

    ll mid = (st+end) / 2;

    return T_min[node] = min(min_init(node*2,st,mid) , min_init(node*2+1, mid+1, end));

}

ll min_find(int node,int st, int end, int left, int right){

    if (end < left || right < st) return 1e9;
    if (left <= st && end <= right) return T_min[node];

    ll mid = (st+end) / 2;

    ll leftTree = min_find(node*2,st,mid,left,right);
    ll rightTree = min_find(node*2 + 1, mid+1, end, left,right);

    return min(leftTree , rightTree);

}

ll max_find(int node,int st, int end, int left, int right){

    if (end < left || right < st) return -1;
    if (left <= st && end <= right) return T_max[node];

    ll mid = (st+end) / 2;

    ll leftTree = max_find(node*2,st,mid,left,right);
    ll rightTree = max_find(node*2 + 1, mid+1, end, left,right);

    return max(leftTree , rightTree);

}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    max_init(1,0,N-1);
    min_init(1,0,N-1);
    //for (int i = 1; i <= 10; i++) cout << T_min[i] << " ";

    
    int a,b;
    for (int i = 0; i < M; i++){
        cin >> a >> b;
        cout << min_find(1,0,N-1,a-1,b-1) << " " << max_find(1,0,N-1,a-1,b-1) << "\n";
    }
    
}