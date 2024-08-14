#include<bits/stdc++.h>


using namespace std;

int N,M;
int A,B;

bool visited[100010];

vector<int> move(int now){

    vector<int> nexts;

    nexts.push_back(now+1);
    nexts.push_back(now-1);

    nexts.push_back(now+A);
    nexts.push_back(now-A);
    nexts.push_back(now+B);
    nexts.push_back(now-B);

    nexts.push_back(now*A);
    nexts.push_back(-now*A);
    nexts.push_back(now*B);
    nexts.push_back(-now*B);

    return nexts;
}


int bfs(){

    queue<int> q;
    visited[N] = true;
    q.push(N);

    int cnt = 0;

    int ans = 1e9;

    while(!q.empty()){
        int size = q.size();
        cnt++;
        while(size--){

            int now = q.front();

            

            q.pop();

            vector<int> nexts = move(now);

            for (int next : nexts){
                if (next < 0 || next > 100000) continue;
                if (visited[next]) continue;
                visited[next] = true;

                if (next == M) ans = min(ans,cnt);

                q.push(next);
            }
        }
       

    }

    return ans;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> A >> B;
    cin >> N >> M;


    cout << bfs();

}