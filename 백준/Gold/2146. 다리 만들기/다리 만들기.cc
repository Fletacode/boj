#include<bits/stdc++.h>


using namespace std;

int N;

bool Map[110][110];

bool visited[110][110];

int parent[10010];

int ay[4] = {-1, 1, 0, 0}; //상하좌우
int ax[4] = { 0, 0,-1, 1};

int find(int a){

    if (parent[a] != a) return parent[a] = find(parent[a]);
    else{
        return a;
    }

}

void uni(int a,int b){
    
    int find_a = find(a);
    int find_b = find(b);

    parent[find_b] = find_a;

}

void zip_land(int sy,int sx){

    //memset(visited,0, 110*110);

    queue<pair<int,int>> q;

    visited[sy][sx] = true;
    q.push({sy,sx});

    while(!q.empty()){
        pair<int,int> p = q.front();
        int y = p.first;
        int x = p.second;
        q.pop();

        for (int i = 0; i < 4; i++){
            int my = y + ay[i];
            int mx = x + ax[i];

            if (my < 0 || my >= N || mx < 0 || mx >= N) continue;
            if (!Map[my][mx] || visited[my][mx]) continue;

            visited[my][mx] = true;
            q.push({my,mx});

            /*
            if (y*N + x + 1 == 21 || my*N + mx + 1 == 21){
                cout << y*N + x + 1 << " " << my*N + mx + 1 << "\n";
            }
            */

            uni(y*N + x + 1, my*N + mx + 1);

        }

    }

}

int find_land(int sy,int sx){

    memset(visited,0, 110*110);

    queue<pair<int,int>> q;

    visited[sy][sx] = true;
    q.push({sy,sx});

    int st_par = parent[sy*N + sx + 1];

    int ans = 1e9;

    int cnt = -1;

    while(!q.empty()){
        int size = q.size();
        cnt++;

        while(size--){
            pair<int,int> p = q.front();
            int y = p.first;
            int x = p.second;
            q.pop();

            for (int i = 0; i < 4; i++){
                int my = y + ay[i];
                int mx = x + ax[i];

                if (my < 0 || my >= N || mx < 0 || mx >= N) continue;
                if (visited[my][mx]) continue;
                if (st_par == parent[my*N + mx + 1]) continue;

                if (Map[my][mx]){
                    ans = min(ans,cnt);
                    //if (cnt == 4) cout << my << " " << mx << "\n"; 
                } 
                else{
                    visited[my][mx] = true;
                    q.push({my,mx});
                }
                
            }


        }

        

    }

    return ans;

}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> Map[i][j];
            parent[i*N + j + 1] = i*N + j + 1;
        }
    }

    
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (!visited[i][j] && Map[i][j]){
                //cout << i << " " << j << "\n";
                zip_land(i,j);
            }
            
        }
    }
    
    /*
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << visited[i][j] << " ";
            
        }
        cout << "\n";
    }
    */

    int ans = 1e9;
    memset(visited,0, 110*110);

    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (!visited[i][j] && Map[i][j]){
                ans = min(ans,find_land(i,j));
            }
            //cout << Map[i][j] << " ";
        }
        //cout << "\n";
    }   
    

    //cout << find_land(4,3);
    

    cout << ans;

    

    //for (int i = 1; i <= 30; i++) cout << parent[i] << " ";
}