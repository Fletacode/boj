#include<bits/stdc++.h>

using namespace std;

int N,M;

int arr[310][310];
bool visited[310][310];

int ax[4] = { 0,0,-1,1};
int ay[4] = { -1,1, 0, 0};

vector< vector<pair<int,int>> > ices;

vector<pair<int,int>> bfs_ice(int i, int j){
    queue<pair<int,int>> q;
    vector<pair<int,int>> v;

    q.push({i,j});
    visited[i][j] = true;
    v.push_back({i,j});

    while(!q.empty()){
        pair<int,int> now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){
            int my = now.first + ay[i];
            int mx = now.second + ax[i];
            if ( my < 0 || my >= N || mx < 0 || mx >= M) continue;
            if (visited[my][mx]) continue;
            if (!arr[my][mx]) continue;

            q.push({my,mx});
            visited[my][mx] = true;
            v.push_back({my,mx});
        }
    }

    return v;
}


void find_ice(){

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            visited[i][j] = false;
        }
    }

    ices.clear();

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (!visited[i][j] && arr[i][j]){
                ices.push_back(bfs_ice(i,j));
            }
        }
    }

   
}



void boil_ices(){

    vector<vector<int>> cnt_v(N+1, vector<int>(M+1,0));

    for (vector<pair<int,int>> ice : ices){
        for (pair<int,int> p : ice){
            int cnt = 0;
            int y = p.first;
            int x = p.second;
            for (int i = 0; i < 4; i++){
                int my = y + ay[i];
                int mx = x + ax[i];
                if ( my < 0 || my >= N || mx <0 || mx >= M) continue;
                
                if (!arr[my][mx]){
                    cnt++;
                }
            }

            cnt_v[y][x] = cnt;

        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (arr[i][j]){
                arr[i][j] = max(0, arr[i][j] - cnt_v[i][j]);
            }
            
        }
    }

}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    cin >> N >> M;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    find_ice();
    
    while(true){
        ans++;
        boil_ices();
        find_ice();
        if (ices.size() >= 2) break;
        if (ices.size() == 0){
            ans = 0;
            break;
        }
        
    }
    


    cout << ans;
    
}