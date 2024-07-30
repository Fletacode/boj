#include<bits/stdc++.h>


typedef long long ll;

using namespace std;

int N,K;

ll A[100010];
ll T[100010 * 4];

ll init(int node, int st, int end){


    if (st == end){
        return T[node] = A[st];
    }

    ll mid = (st+end) / 2;
    
    ll left_node = init(node * 2, st, mid);
    ll right_node = init(node * 2 + 1, mid + 1 ,end);

    ll ret = 1;
    ret = left_node * right_node;

    
    if (ret > 0) ret = 1;
    else if (ret < 0) ret = -1;
    else{
        ret = 0;
    }
    

    return T[node] = ret;

}

ll find_num(int node, int st, int end, int left ,int right){

    if (end < left || right < st) return 1;

    if (left <= st && end <= right){
        return T[node]; 
    }

    ll mid = (st+end) / 2;

    ll left_node = find_num(node*2, st, mid, left, right);
    
    ll right_node = find_num(node*2 + 1, mid+1, end, left, right);

    ll ret = left_node * right_node;

    if (ret > 0) ret = 1;
    else if (ret < 0) ret = -1;
    else{
        ret = 0;
    }

    return ret;

}

void update(int node, int st, int end, int idx,int val){

    if (st > idx || end < idx) return;

    if (st == end){
        T[node] = val;
        A[st] = val;
        return;
    }


    ll mid = (st+end) / 2;

    if (idx <= mid) update(node*2, st, mid, idx, val);
    else{
        update(node*2 + 1, mid+1, end, idx, val);
    }

    ll ret = T[node*2] * T[node*2+1];

    if (ret > 0){
        T[node] = 1;
    }else if (ret < 0){
        T[node] = -1;
    }else{
        T[node] = 0;
    }

}


int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);

    

    while(cin >> N){
        cin >> K;

        memset(A, 0, sizeof(A));
        memset(T, 0, sizeof(T));

       

        for (int i = 0; i < N; i++){
            cin >> A[i];
        }

        init(1, 0, N-1);

        //for (int i = 1; i < N*4; i++) cout << T[i] << " ";
        //cout << "\n";


        string input;
        int a,b;
        while(K--){
            cin >> input;
            cin >> a >> b;

            if (input == "P"){
                ll ret = find_num(1,0,N-1, a-1, b-1);
                if (ret == 0){
                    cout << "0";
                }else if (ret > 0){
                    cout << "+";
                }else{
                    cout << "-";
                }
            }else{
                update(1, 0, N-1, a-1, b);
            }

        }

        cout << "\n";
    }
    


}