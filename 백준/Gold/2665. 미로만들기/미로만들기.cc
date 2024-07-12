#include<bits/stdc++.h>


using namespace std;


int N;
string str;

int MAP[55][55];
int V[55][55];

int my[4] = {-1,1,0,0}; //상하좌우
int mx[4] = {0,0,-1,1};

void diestra(){

    priority_queue<pair<int,pair<int,int>> > pq;
    
    if (!MAP[0][0]){
        pq.push({-1,{0,0}});
        V[0][0] = 1;
    }else{
        pq.push({0,{0,0}});
        V[0][0] = 0;
    }


    while(!pq.empty()){
        pair<int,pair<int,int>> p = pq.top();
        int nowv = -p.first;
        pair<int,int> now = p.second;
        int x = now.second;
        int y = now.first;
        pq.pop();

        for (int i = 0; i < 4; i++){
            int dy = y + my[i];
            int dx = x + mx[i];
            if (dx < 0 || dx >= N || dy < 0 || dy >= N) continue;

            if (!MAP[dy][dx] && V[dy][dx] > nowv +  1){

                V[dy][dx] = nowv + 1;
                pq.push({-(nowv + 1), {dy,dx}});

            }else if (MAP[dy][dx] && V[dy][dx] > nowv ){
                V[dy][dx] = nowv ;
                pq.push({-(nowv), {dy,dx}});
            }

            
        }



    }



}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);



    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> str;
        for (int j = 0; j < str.size(); j++){
            MAP[i][j] = str[j] - '0';
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            V[i][j] = 1e9;
        }
    }

    diestra();

    /*
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << V[i][j] << " ";
        }
        cout << "\n";
    }
    */
    cout << V[N-1][N-1];

}
