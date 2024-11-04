#include<bits/stdc++.h>


using namespace std;

int N,K;
bool visited[250000];

int MAX_DIS = 100000;

int bfs(){
    int ans = 1e9;

    queue<int> q;
    q.push(N);
    visited[N] = true;

    int cnt = -1;

    while(!q.empty()){
        
        cnt += 1;
        int size = q.size();

        while(size--){
            int now = q.front();
            q.pop();

            if (now == K) ans = min(cnt, ans);

        if (now + 1 <= MAX_DIS && !visited[now + 1]){
            visited[now + 1] = true;
            q.push(now + 1);
        }

        if (now - 1 >= 0 && !visited[now - 1]){
            visited[now - 1] = true;
            q.push(now - 1);
        }

        if (now * 2 <= MAX_DIS && !visited[now * 2]){
            visited[now * 2] = true;
            q.push(now * 2);
        }

        }

    }

    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;

    cout << bfs();
    
   
}