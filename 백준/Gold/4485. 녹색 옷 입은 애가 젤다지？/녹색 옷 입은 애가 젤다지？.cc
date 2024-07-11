#include<bits/stdc++.h>


using namespace std;

int N;

int MAP[130][130];
int V[130][130];

int my[4] = {-1,1,0,0}; //상하좌우
int mx[4] = {0,0,-1,1};

void diestra(){
    priority_queue<pair<int,pair<int,int>> > pq;

    pq.push({-MAP[0][0],{0,0}});
    V[0][0] = MAP[0][0];


    while(!pq.empty()){
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        int val = -pq.top().first;
        pq.pop();


        for (int i = 0; i < 4; i++){
            int dy = y + my[i];
            int dx = x + mx[i];
            if (dy < 0 || dy >= N || dx < 0 || dx >= N) continue;
            int next_val = val + MAP[dy][dx];
            if (V[dy][dx] > next_val){
                V[dy][dx] = next_val;
                pq.push({-next_val,{dy,dx}});
                
            }

        }

    }


}


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int cnt = 1;

    while(true){
        cin >> N;
        if (N == 0) break;

        for (int i = 0; i < 126; i++) memset(MAP[i],0,sizeof(MAP[i]));
        for (int i = 0; i < 126; i++) {
            for (int j = 0; j < 126; j++){
                V[i][j] = 1e9;
            }
        }

        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                cin >> MAP[i][j];
            }
        }

        diestra();

        cout <<"Problem " << cnt++ << ": " << V[N-1][N-1] << "\n";

    }


}