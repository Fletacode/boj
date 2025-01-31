#include<bits/stdc++.h>


using namespace std;

int T,N;

int parent[10010];
bool visited[10010];


void init(){
    
    memset(visited, 0, sizeof(visited));

    memset(parent, 0, sizeof(parent));

}

void input_fun(){
    int a,b;
    for (int i = 0; i < N-1; i++){
        cin >> a >> b;
        parent[b] = a;
    }
}

int find_parent(int a,int b){

    int now = a;

    while(now != 0){
        visited[now] = true;
        now = parent[now];
    }

    now = b;

    while(now != 0){
        if (visited[now]){
            return now;
        }
        visited[now] = true;
        now = parent[now];
    }


    return -1;
}

void print_parent(){

    for (int i = 1; i <= N; i++){
        cout << parent[i] << " ";
        
    }
    cout << "\n";
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    cin >> T;

    while(T--){
        cin >> N;

        init();
        input_fun();
        int a,b;
        cin >> a >> b;

        //print_parent();

        cout << find_parent(a,b) << "\n";

    }


}