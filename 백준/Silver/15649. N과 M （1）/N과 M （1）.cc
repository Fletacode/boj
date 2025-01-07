#include<bits/stdc++.h>


using namespace std;

int N, M;
vector<int> v;

bool visited[10];

void go(int depth){

    if (depth == M){
        for (int i : v) cout << i << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++){
        if (visited[i]) continue;

        visited[i] = true;
        v.push_back(i);
        go(depth + 1);
        visited[i] = false;
        v.pop_back();
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    
    go(0);
}