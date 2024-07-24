#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int N;
ll A[510][510];


ll visited[510][510];


int ay[4] = {-1,1,0,0};
int ax[4] = {0,0,-1,1};

ll dfs(int y, int x){


    visited[y][x] = 1;

    ll max_val = 0;

    for (int i = 0; i < 4; i++){
        int my = ay[i] + y;
        int mx = ax[i] + x;
        if (my < 0 || my >= N || mx < 0 || mx >= N) continue;

        
        if (visited[my][mx] && A[y][x] < A[my][mx]){
           max_val = max(max_val,visited[my][mx]);
            continue;
        }
        

        if (A[y][x] < A[my][mx]){
            //visited[y][x] += dfs(my,mx);
            max_val = max(max_val,dfs(my,mx));
        }

    }

    visited[y][x] += max_val;

    return visited[y][x];

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> A[i][j];
        }
    }

    ll max_ans = -1;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            
            if (visited[i][j]) continue;

            max_ans = max( dfs(i,j), max_ans);

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

    cout << max_ans;
    

    
   
}