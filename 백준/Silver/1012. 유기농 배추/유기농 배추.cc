#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int N,M,K,T;

bool Map[51][51];
bool visited[51][51];

int ay[4] = {1,-1, 0,0};
int ax[4] = {0, 0,-1,1};


void dfs(int y, int x){

    for (int i = 0; i < 4; i++){
        int my = y + ay[i];
        int mx = x + ax[i];

        if (my < 0 || my >= N || mx < 0 || mx >= M) continue;
        if (visited[my][mx]) continue;
        if (!Map[my][mx]) continue;

        visited[my][mx] = true;
        dfs(my,mx);
    }

}


int sol(){

    int ans = 0;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (visited[i][j]) continue;
            if (!Map[i][j]) continue;

            dfs(i,j);
            ans++;
        }
    }
    return ans;
}

void input_fun(){

    cin >> M >> N >> K;
    int x,y;
    for (int i = 0; i < K; i++){
        cin >> x >> y;
        Map[y][x] = 1;
    }

}

void init(){
    memset(Map, false, sizeof(Map));
    memset(visited, false, sizeof(visited));
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;

    while(T--){
        init();
        input_fun();
        cout << sol() << "\n";
    }
    
}