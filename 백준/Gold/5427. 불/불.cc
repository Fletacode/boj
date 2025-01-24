#include<bits/stdc++.h>


using namespace std;

int T,W,H;
char Map[1010][1010];
bool visited[1010][1010];

vector<pair<int,int>> fires;
pair<int,int> man;

int ay[4] = {-1,1,0,0};
int ax[4] = { 0,0,-1,1};

void init(){

    fires.clear();

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++){
            Map[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

void input_fun(){
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++){
            cin >> Map[i][j];
            if (Map[i][j] == '*') fires.push_back({i,j});
            else if (Map[i][j] == '@') {
                man = {i,j};
            }
        }
    }
}

void fire_move(){

    vector<pair<int,int>> temp;

    for (pair<int,int> fire : fires){
        int y = fire.first;
        int x = fire.second;

        for (int i = 0; i < 4; i++){
            int my = ay[i] + y;
            int mx = ax[i] + x;

            if (my <= 0 || my > H || mx <= 0 || mx > W) continue;
            
            if (Map[my][mx] == '#' || Map[my][mx] == '*') continue;

            Map[my][mx] = '*';
            temp.push_back({my,mx});
        }

    }

    fires = temp;

}

int bfs(){

    queue<pair<int,int>> q;
    q.push(man);
    visited[man.first][man.second] = true;

    int cnt = -1;


    while(!q.empty()) {

        int size = q.size();
        cnt += 1;

        fire_move();

        while(size--){
            pair<int,int> now = q.front();
            q.pop();

            int y = now.first;
            int x = now.second;

            


            for (int i = 0; i < 4; i++){
                int my = ay[i] + y;
                int mx = ax[i] + x;

                if (my <= 0 || my > H || mx <= 0 || mx > W) {
                    return cnt + 1;
                }

                if (visited[my][mx]) continue;
                if (Map[my][mx] == '#' || Map[my][mx] == '*') continue;

                q.push({my,mx});
                visited[my][mx] = true;
            }


        }

    }

    return -1;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;

    while(T--){
        cin >> W >> H;

        init();
        input_fun();
        int ans = bfs();
        if (ans == -1){
            cout << "IMPOSSIBLE\n";
        } else{
            cout << ans << "\n";
        }
       

    }

}