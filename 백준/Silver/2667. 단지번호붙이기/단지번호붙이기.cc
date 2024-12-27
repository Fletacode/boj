#include<bits/stdc++.h>


using namespace std;

int N;

int A[30][30];
bool visited[30][30];

int ay[4] = {-1,1,0,0};
int ax[4] = {0,0,-1,1};

int bfs(int i, int j){
    queue<pair<int,int>> q;

    q.push({i,j});
    visited[i][j] = true;
    int cnt = 0;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        cnt++;

        for (int i = 0; i < 4; i++){
            int my = y + ay[i];
            int mx = x + ax[i];

            if (my < 0 || my >= N || mx < 0 || mx >= N) continue;
            if (visited[my][mx]) continue;
            if (A[my][mx] == 0) continue;

            visited[my][mx] = true;
            q.push({my,mx});
        }

    }

    return cnt;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    string str;

    for (int i =0; i < N; i++){
        cin >> str;
        for (int j = 0; j < str.size(); j++){
            int num = str[j] - '0';
            A[i][j] = num;
            
        }
        
    }

    vector<int> v;
    int ans = 0;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (!visited[i][j] && A[i][j] == 1){
                int num = bfs(i,j);
                v.push_back(num);
                ans += 1;
            }
        }
    }

    sort(v.begin(), v.end());

    cout << ans << "\n";

    for (int i : v){
        cout << i << "\n";
    }

}