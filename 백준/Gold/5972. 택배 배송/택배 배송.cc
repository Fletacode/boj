#include<bits/stdc++.h>

using namespace std;

int N,M;


vector<pair<int,int>> v[50010];

int V[50010];

void diestra(){
    
    priority_queue<pair<int,int>> pq;
    pq.push({0,1});
    V[1] = 0;

    while(!pq.empty()){
        pair<int,int> p = pq.top();
        int now = p.second;
        int val = -p.first;
        pq.pop();

        for (int i = 0; i < v[now].size(); i++){
            pair<int,int> p2 = v[now][i];
            int next = p2.second;
            int next_val = p2.first;


            if (V[next] > V[now] + next_val){
                V[next] = V[now] + next_val;
                pq.push({-(next_val + V[now]),next});
            }

        }

    }


}



int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    cin >> N >> M;

    int a,b,c;

    for (int i = 0; i < M; i++){
        cin >> a >> b >> c;
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }

    for (int i = 1; i <= N; i++) V[i] = 1e9;

    diestra();

    cout << V[N];
}