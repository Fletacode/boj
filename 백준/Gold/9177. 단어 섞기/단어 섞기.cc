#include<bits/stdc++.h>


using namespace std;

int T;
string SA[3];

bool visited[210][210];

struct node{
    int oneidx;
    int twoidx;
    int findidx;
};

bool bfs(){
    queue<node> q;
    q.push({0,0,0});
    visited[0][0] = true;

    while(!q.empty()){
        int one_idx = q.front().oneidx;
        int two_idx = q.front().twoidx;
        int find_idx = q.front().findidx;
        q.pop();

        if (find_idx >= SA[2].size()) return true;

        if (one_idx < SA[0].size() &&
            SA[0][one_idx] == SA[2][find_idx] &&
            !visited[one_idx+1][two_idx]){

            q.push({one_idx + 1,two_idx,find_idx + 1});
            visited[one_idx + 1][two_idx] = true;
        }

        if (two_idx < SA[1].size() &&
           SA[1][two_idx] == SA[2][find_idx] &&
           !visited[one_idx][two_idx+1]){

            q.push({one_idx, two_idx + 1, find_idx + 1});
            visited[one_idx][two_idx + 1] = true;
        }


    }

    return false;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;
    int t_cnt = 1;
    while(T--){
        cin >> SA[0] >> SA[1] >> SA[2];

        memset(visited, 0 , 210 * 210);

        if (bfs()){
            cout << "Data set " << t_cnt << ": yes\n";
        }else{
            cout << "Data set " << t_cnt << ": no\n";
        }

        t_cnt++;

    } 

}