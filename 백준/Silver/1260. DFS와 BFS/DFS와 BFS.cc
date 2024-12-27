#include<bits/stdc++.h>


using namespace std;

typedef long long ll;

int N,M,st;

vector<int> A[1010];


bool visited[1010];

void dfs(int now){

    for (int i = 0; i < A[now].size(); i++){
        int next = A[now][i];
        if (visited[next]) continue;
        visited[next] = true;
        cout << next << " ";
        dfs(next);
        
    }

}


void bfs(int st){
    queue<int> q;

    q.push(st);
    visited[st] = true;

    while(!q.empty()){
        int now = q.front();
        q.pop();
        cout << now << " ";

        for (int i = 0; i < A[now].size(); i++){
            int next = A[now][i];
            if (visited[next]) continue;

            visited[next] = true;
            q.push(next);

        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> st;

    for (int i = 0; i < M; i++){
        int a,b;
        cin >> a >> b;
        A[a].push_back(b);
        A[b].push_back(a);
    }

    for (int i = 1; i <= N; i++){
        sort(A[i].begin(), A[i].end());
    }

    //dfs
    cout << st << " ";
    visited[st] = true;
    dfs(st);
    cout << "\n";
    memset(visited, false, sizeof(visited));

    bfs(st);

}