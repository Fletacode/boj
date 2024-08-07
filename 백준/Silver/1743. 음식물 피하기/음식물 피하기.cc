#include<bits/stdc++.h>


using namespace std;

int N , M , K;

int Map[110][110];

int ay[4] = {-1, 1, 0,  0}; //상하좌우
int ax[4] = { 0, 0, -1, 1};

bool visited[110][110];

vector<pair<int,int>> v;

int dfs(int y, int x, int depth){

    if (visited[y][x]) return depth;

    visited[y][x] = true;

    for (int i = 0; i < 4; i++){
        int my = y + ay[i];
        int mx = x + ax[i];

        if (my <= 0 || my > N || mx <= 0 || mx > M) continue;

        if (Map[my][mx] && !visited[my][mx]){
            depth = max(dfs(my,mx, depth + 1), depth);
        }


    }

    return depth;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;

    int y,x;
    for (int i = 0; i < K; i++){
        cin >> y >> x;
        Map[y][x] = 1;
        v.push_back({y,x});
    }

    int ans = 0;

    for (pair<int,int> p : v){
        ans = max(ans, dfs(p.first,p.second, 1));
    }

    cout << ans;


}