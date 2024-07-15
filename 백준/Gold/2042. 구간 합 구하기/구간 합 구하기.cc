#include<bits/stdc++.h>

typedef long long ll;

using namespace std;



int N,M,K;

ll A[1000010];
ll T[1000010 * 4];

ll init(int node , int st, int end){

    if (st == end) return T[node] = A[st]; 

    ll mid = (st+end) / 2;
    ll left_result = init(node*2, st, mid);
    ll right_result = init(node*2 + 1, mid + 1, end);
    T[node] =  left_result + right_result;
    return T[node];

}

void update(int node,int st,int end,int idx,ll diff){

    if (idx < st || end < idx) return;

 
    T[node] = T[node] + diff;
     
    if (st != end){
        ll mid = (st+end) / 2;
        update(node*2,st,mid,idx,diff);
        update(node*2 + 1, mid + 1,end,idx,diff);
    }

}

ll sum(int node,int st, int end, int left, int right){
    
    if (end < left || right < st){
        return 0;
    }
    if (left <= st && end <=  right) return T[node];

   
    ll mid = (st+end) / 2;
    ll leftTree = sum(node*2, st, mid,left,right);
    ll rightTree = sum(node*2+1, mid+1, end, left, right);

    return leftTree + rightTree;
    

    
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    cin >> N >> M >> K;

    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    init(1,0,N-1);
    //cout << T[1] << "\n";

    ll a,b,c;
    for (int i = 0; i < M+K; i++){
        cin >> a >> b >> c;

        if (a == 1){
            
            ll diff = c - A[b-1];
            A[b-1] = c;   
            update(1,0,N-1,b-1,diff);  
                   
        }else{
            cout << sum(1,0,N-1,b-1,c-1) << "\n";
        }


    }

    //cout << T[1];


}