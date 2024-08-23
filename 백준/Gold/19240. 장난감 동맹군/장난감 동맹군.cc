#include<bits/stdc++.h>


using namespace std;

int T,N,M;

bool team[300010];

vector<int> v[300010];

bool visited[300010];



void dfs(int now, bool t){

    t = !t;

    visited[now] = true;
    team[now] = t;

    

    for (int next : v[now]){

        if (visited[next]) continue;
        dfs(next, t);
    }

}

bool check_t(){
    for (int i = 1; i <= N; i++){
            for (int next : v[i]){
                if (team[i] == team[next]){
                    return false;
                    
                }
            }
        }

    return true;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    cin >> T;

    while(T--){
        cin >> N >> M;

        memset(team,0,sizeof(team));
      
        memset(visited, 0 ,sizeof(visited));

        int a,b;

        while(M--){

            cin >> a >> b;

            v[a].push_back(b);
            v[b].push_back(a);
        }

        for (int i = 1; i <= N; i++){
            if (visited[i]) continue;

            dfs(i,false);
        }



        if (check_t()){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }

        for (int i = 1; i <= N; i++){
        
            v[i].clear();
        }
    }



}