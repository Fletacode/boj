#include<bits/stdc++.h>

typedef long long ll;

using namespace std;


int N,M;

ll A[1000010];
ll T[1000010 * 4];

ll sum(int node, int st, int end, int left,int right){
    if (end < left || right < st) return 0;

    if (left <= st && end <= right) return T[node];

    ll mid = (st+end) / 2;

    ll leftTree = sum(node*2,st,mid, left, right );
    ll rightTree = sum(node*2+1, mid + 1, end, left, right);

    return leftTree + rightTree;
}

void update_tree(int node, int st, int end, int idx, ll val){
    

    if (st == end){
        T[node] = val;
        return;
    }

   
    ll mid = (st+end) / 2;

    if (idx <= mid)update_tree(node*2, st, mid, idx, val);
    else{
        update_tree(node*2 + 1, mid + 1, end, idx, val);
    }
    T[node] = (T[node*2] + T[node*2 + 1]);

    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;



    ll a,b,c;   
    while(M--){
        cin >> a;
        if (a == 0){
            cin >> b >> c;
            if (b > c){
                ll temp = b;
                b = c;
                c = temp;
            }
            cout << sum(1,0,N-1,b-1, c-1) << "\n";
        }else{
            cin >> b >> c;
            
            A[b-1] = c;
            update_tree(1,0,N-1, b-1,c);
        } 

        //for (int i = 1; i <= N*4; i++) cout << T[i] << " ";
        //cout << "\n";
    }


    
}