#include<bits/stdc++.h>

using namespace std;

int N,M;

vector<int> A[510];
bool visited[510];


bool dfs(int now,int prev){

    visited[now] = true;

    for (int i = 0; i < A[now].size(); i++){
        int next = A[now][i];
        if (prev == next) continue;

        if (visited[next]) {
            return false;
        }

        if (!dfs(next,now)) return false;
        
    }

    return true;

}

void print_ans(int cnt,int ans){

    string scnt = to_string(cnt);
    string sans = to_string(ans);

    if (ans == 0){
        cout << "Case "+ scnt + ": " + "No trees.\n";
    } else if (ans == 1){
        cout << "Case "+ scnt + ": " + "There is one tree.\n";
    } else {
        cout << "Case "+ scnt + ": " + "A forest of " + sans + " trees.\n";
    }


}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    int cnt = 0;

    while(true){
        cin >> N >> M;
        if (N == 0 && M == 0){
            break;
        }

        cnt++;

        for (int i = 0; i < 510; i++){
            visited[i] = false;
            A[i].clear();
        }

        int a,b;
        for (int i = 0; i < M; i++){
            cin >> a>> b;
            A[a].push_back(b);
            A[b].push_back(a);
        }

        int ans = 0;

        for (int i = 1; i <= N; i++){
            if (visited[i]) continue;
            if (dfs(i,0)) ans++;

        }


        print_ans(cnt,ans);


    }

}