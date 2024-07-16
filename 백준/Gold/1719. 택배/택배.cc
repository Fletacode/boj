#include<bits/stdc++.h>


using namespace std;

int N,M;

vector<pair<int,int>> A[210];
int V[210];

int ans[210][210];

int U[210];


int find(int a){
    if (U[a] != a) return U[a] = find(U[a]);
    return a; 
}

void uni(int a, int b){
    //int fa = find(a);
    //int fb = find(b);

    U[b] = a;

}

void find_ans(int st){
    for (int i = 1; i <= N; i++){
        int find_num = find(i);
        ans[st][i] = find_num;
    }
}


void diestra(int st){
    for (int i = 1; i <= N; i++) V[i] = 1e9;
    for (int i = 1; i <= N; i++) U[i] = i;
    priority_queue<pair<int,int>> pq;


    pq.push({0,st});
    V[st] = 0;

    pair<int,int> p = pq.top();
    int now_val = -p.first;
    int now = p.second;
    pq.pop();

    for (int i = 0; i < A[now].size(); i++){
        int next_val = A[now][i].first;
        int next = A[now][i].second;

        if (V[next] > next_val + now_val){
            V[next] = next_val + now_val;
          
            pq.push({-V[next], next});
                
        }

    }


    while(!pq.empty()){
        pair<int,int> p = pq.top();
        int now_val = -p.first;
        int now = p.second;
        pq.pop();

        for (int i = 0; i < A[now].size(); i++){
            int next_val = A[now][i].first;
            int next = A[now][i].second;

            if (V[next] > next_val + now_val){
                V[next] = next_val + now_val;
                uni(now,next);
                pq.push({-V[next], next});
                
            }

        }



    }

    find_ans(st);


}







int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    cin >> N >> M;

    int a,b,c;

    

    for (int i = 0; i < M; i++){
        cin >>a >> b >> c;
        A[a].push_back({c,b});
        A[b].push_back({c,a});
        
    }

    for (int i = 1; i <= N; i++) diestra(i);
    //diestra(5);
    

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            if (i == j){
                cout << "- ";
                continue;
            }
            cout << ans[i][j] << ' ';
        }
        cout << "\n";
    }

    //for (int i = 1; i <= N; i++) cout << U[i] <<" ";


}