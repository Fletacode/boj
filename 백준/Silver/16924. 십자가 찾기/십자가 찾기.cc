#include<bits/stdc++.h>

using namespace std;


int N,M;

char Map[110][110];
bool visited[110][110];

int ay[4] = {-1,1,0,0};
int ax[4] = { 0,0,-1,1};

vector<pair<int,pair<int,int>>> ans; 

int find(int y, int x,int s){
    for (int i = 0; i < 4; i++){
        int my = y + ay[i] * s;
        int mx = x + ax[i] * s;


        if (my < 0 || my >= N || mx < 0 || mx >= M) return s-1;

        if (Map[my][mx] != '*') return s-1; 

    }


    //크기 s에서 모든 위치 성립립
    for (int i = 0; i < 4; i++){
        int my = y + ay[i] * s;
        int mx = x + ax[i] * s;

        visited[my][mx] = true;
    }


    return find(y,x,s+1);

}

bool check_ans(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (Map[i][j] == '*' && !visited[i][j]) return false;
        }
    }

    return true;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    cin >> N >> M;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> Map[i][j];
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (Map[i][j] == '*'){
               
                int max_size = find(i,j,1);

                if (max_size > 0){
                   visited[i][j] = true;
                   ans.push_back({max_size,{i+1,j+1}});
                }

            }
        }
    }


    if (check_ans()){
        cout << ans.size() << "\n";

    for (pair<int,pair<int,int>> p : ans){
        cout << p.second.first << " " << p.second.second << " " << p.first << "\n";
    }
    } else{
        cout << -1;
    }

    

}