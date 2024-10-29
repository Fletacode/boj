#include<bits/stdc++.h>


using namespace std;

int N,M;

int A[510][510];

vector<pair<int,int>> v;

int visited[510][510];

int ay[4] = {-1,1, 0,0};
int ax[4] = { 0,0,-1,1};

int cnt = 0;

int cal_rect(int sy, int sx){
    
    queue<pair<int,int>> q;
        
    q.push({sy,sx});
    
    cnt += 1;
    
    int width = 1;
    
    visited[sy][sx] = cnt;
    
    while(!q.empty()){
        pair<int,int> now = q.front();
        
        q.pop();

        int y = now.first;
        int x = now.second;
        
        
        for (int i = 0; i < 4; i++){
            int my = y + ay[i];
            int mx = x + ax[i];
            
            if (my < 0 || my >= N || mx < 0 || mx >= M){
                continue;
            }

            if (!A[my][mx]) continue;
            
            if (visited[my][mx]) continue;
            
            q.push({my,mx});
            visited[my][mx] = cnt;
            width += 1;
            
        }
       
    }
    
    return width;
    
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> A[i][j];
            if (A[i][j] == 1){
                v.push_back({i,j});
            } 
        }
    }
    
    int max_width = 0;
   
    
    for (pair<int,int> p : v){
        int y = p.first;
        int x = p.second;
        if (!visited[y][x]){
            max_width = max(max_width,cal_rect(y,x));
        }
    }
    
    cout << cnt << "\n" << max_width;
    
}