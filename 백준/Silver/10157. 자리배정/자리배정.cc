#include<bits/stdc++.h>


using namespace std;



int C,R,K;

int ax[4] = {0,1,0,-1}; //상우하좌
int ay[4] = {-1,0,1,0};

int MAP[1010][1010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> C >> R >> K;

    int cnt = 1;
    int idx = 0;
    int y = R-1;
    int x = 0;
    MAP[y][x] = cnt++;

    while(cnt <= C*R){

        int my = y + ay[idx];
        int mx = x + ax[idx];

        if (MAP[my][mx] || my < 0 || my >= R
           || mx < 0 || mx >= C){
            idx = (idx + 1) % 4;

            my = y + ay[idx];
            mx = x + ax[idx];
            MAP[my][mx] = cnt++;
            y = my;
            x = mx;
        }else{

            MAP[my][mx] = cnt++;
            y = my;
            x = mx;
        }

    }

    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            //cout << MAP[i][j] << " ";
            
            if (MAP[i][j] == K){
                cout << j+1 << " " << (R-i);
                return 0;
            }
            
        }
        //cout << "\n";
        
    }

    cout << 0;
   

}