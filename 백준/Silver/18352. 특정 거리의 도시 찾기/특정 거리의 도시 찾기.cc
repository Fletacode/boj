#include<bits/stdc++.h>


using namespace std;


int N,M,K,X;

vector<int> MAP[300010];

int visited[300010];

void bfs(int st){
    queue<int> q;

    int depth = 0;

    q.push(st);
    visited[st] = depth;

    while(!q.empty()){
        
        int size = q.size();
        depth++;

        while(size--){
            int now = q.front();
            q.pop();

            for (int i = 0; i < MAP[now].size(); i++){
                int next = MAP[now][i];
                if (visited[next] > depth){
                    visited[next] = depth;
                    q.push(next);
                }
            }
        }
        
    }



}

vector<int> cal_ans(){

    vector<int> ans;

    for (int i = 1; i <= N; i++){
        if (visited[i] == K) ans.push_back(i);
    }

    return ans;

}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K >> X;

    int a,b;

    for (int i = 0; i < M; i++){
        cin >> a >> b;
        MAP[a].push_back(b);
    }

    for (int i = 0; i < 300001; i++) visited[i] = 1e9;


    bfs(X);

    vector<int> ans = cal_ans();

    if (!ans.size()) {
        cout << -1;
        return 0;
    }

    sort(ans.begin(), ans.end());

    

    for (int i : ans) cout << i << "\n";

}