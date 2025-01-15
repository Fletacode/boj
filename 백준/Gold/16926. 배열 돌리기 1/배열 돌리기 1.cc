#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int N,M,R;

int A[310][310];

void sol(){

    

    int total_cnt = R;

    while(total_cnt--){

        int cnt_N = N+1;
        int cnt_M = M+1;

        for (int i = 1; i <= min(N,M) / 2; i++){

        int y = i;
        int x = i;
        
        cnt_N -= 2;
        cnt_M -= 2;

        int init = A[y][x];

        

        for (int j = 0; j < cnt_M; j++){
            A[y][x] = A[y][x+1];
            x++;
        }

        for (int j = 0; j < cnt_N; j++){
            A[y][x] = A[y+1][x];
            y++;
        }

        for (int j = 0; j < cnt_M; j++){
            A[y][x] = A[y][x-1];
            x--;
        }

        for (int j = 0; j < cnt_N-1; j++){
            A[y][x] = A[y-1][x];
            y--;
        }
        
        A[i+1][i] = init;

        }
    }

   
    
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> R;
    
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            cin >> A[i][j];
        }
    }

    sol();

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }


}