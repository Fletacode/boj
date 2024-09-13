#include<bits/stdc++.h>

typedef long long ll;

using namespace std;


vector<int> Links[100010];

ll Pluss[100010];

ll Ans[100010];

bool visited[100010];

int N,M;

void cal(int now,ll val){
    
    visited[now] = true;
    Ans[now] += val;
    
    for (int i = 0; i < Links[now].size(); i++){
        int next = Links[now][i];
        
        if (visited[next]) continue;

        cal(next,val + Pluss[now]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++){
        int num;
        cin >> num;
        if (num == -1) continue;
        Links[num].push_back(i);
    }

    for (int k = 0; k < M; k++){
        ll i , w;
        cin >> i >> w;
        Pluss[i] += w;
        Ans[i] += w;
    }

    for (int i = 1; i <= N; i++){
        if (visited[i]) continue;
        cal(i,0);
    }

    for (int i = 1; i <= N; i++){
        cout << Ans[i] << " ";
    }


}