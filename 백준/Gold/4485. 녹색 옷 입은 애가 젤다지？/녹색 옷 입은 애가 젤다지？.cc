#include<bits/stdc++.h>

using namespace std;


int MAP[130][130];
int V[130][130];

int my[4] = {-1,1,0,0}; //상하좌우 
int mx[4] = {0,0,-1,1};
queue<pair<int,pair<int,int>>> q;
int N;

void bfs(){

    while(!q.empty()) q.pop();
    

    q.push({MAP[0][0],{0,0}});
    V[0][0] = MAP[0][0];

    
    while(!q.empty()){
        pair<int,int> now = q.front().second;
        int val = q.front().first;
        q.pop();

        
        for (int i = 0; i < 4; i++){
            int dy = my[i] + now.first;
            int dx = mx[i] + now.second;
            if (dy < 0 || dy >= N || dx < 0 || dx >= N) continue;
            if (MAP[dy][dx] + val >= V[dy][dx]) continue;

            q.push({MAP[dy][dx] + val,{dy,dx}});
            V[dy][dx] = MAP[dy][dx] + val;

        }


    }


}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int cnt = 1;
    while(true){


        cin >> N;
        if (N ==0) break;

        for (int i = 0; i < 126; i++) memset(MAP[i],0,sizeof(MAP[i]));
        for (int i = 0; i < 126; i++) memset(V[i],98765432,sizeof(V[i]));
        

        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                cin >> MAP[i][j];
            }
        }

        bfs();

        cout << "Problem "<< cnt++ << ": " << V[N-1][N-1] << "\n";

    }

    


    return 0;
}