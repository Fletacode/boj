#include<bits/stdc++.h>


using namespace std;

int N,K;
bool visited[200000];

const int maxLength = 100010;

int bfs(int st){

    queue<int> q;
    visited[st] = true;
    q.push(st);
    int cnt = -1;

    while(!q.empty()){
        cnt++;
        int size = q.size();

        while(size--){
            int next = q.front();
            q.pop();

            if (next == K){
                return cnt;
            }

            if (next-1 >= 0 && !visited[next-1]){
                q.push(next-1);
                visited[next-1] = true;
            }

            if (next+1 <= maxLength && !visited[next+1]){
                q.push(next+1);
                visited[next+1] = true;
            }

            if (next*2 <= maxLength && !visited[next*2]){
                q.push(next*2);
                visited[next*2] = true;
            }

        }
        

    }

    return cnt;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;

    cout << bfs(N);




}