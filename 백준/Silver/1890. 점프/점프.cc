#include<bits/stdc++.h>


typedef long long ll;

using namespace std;

int N;
int A[110][110];

int ay[2] = {1,0};
int ax[2] = {0,1};

ll visited[110][110];

ll dfs(int y,int x){

    if (y == N-1 && x == N-1){
        return 1;
    }

    if (A[y][x] == 0) return 0;

    if (visited[y][x]) return visited[y][x];

    for (int i = 0; i < 2; i++){
        int my = y + ay[i] * A[y][x];
        int mx = x + ax[i] * A[y][x];

        if (my < 0 || my >= N || mx >= N || mx < 0) continue;

        
        visited[y][x] += dfs(my,mx);

    }

    return visited[y][x];

}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++){
        for (int j = 0 ; j < N; j++){
            cin >> A[i][j];
        }
    }

    cout << dfs(0,0) << "\n";
    
    /*
    for (int i = 0; i < N; i++){
        for (int j = 0 ; j <N; j++){
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
    */
}