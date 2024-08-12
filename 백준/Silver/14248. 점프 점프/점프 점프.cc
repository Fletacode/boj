#include<bits/stdc++.h>


using namespace std;

int n;

int A[100010];

int s;

bool visited[100010];

void bfs(int st){

    queue<int> q;
    q.push(st);

    visited[st] = true;

    while(!q.empty()){
        int now = q.front();

        int move = A[now];
        q.pop();

        if (now+move <= n && !visited[now+move]){
            q.push(now+move);
            visited[now+move] = true;
        }

        if (now-move > 0 && !visited[now-move]){
            q.push(now-move);
            visited[now-move] = true;
        }


    }

}

int cal_ans(){
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if (visited[i]) ans++;
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for (int i = 1; i <= n; i++){
    
        cin >> A[i];
        
    }

    cin >> s;

    bfs(s); 

    cout << cal_ans();

}