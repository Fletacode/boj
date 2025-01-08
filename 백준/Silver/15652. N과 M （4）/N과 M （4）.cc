#include<bits/stdc++.h>

using namespace std;

int N,M;

vector<int> v;


void go(int depth,int st){

    if (depth >= M){
        for (int i : v) cout << i << " ";
        cout << "\n";
        return;
    }
    
    for (int i = st; i <= N; i++){
        
        v.push_back(i);
        go(depth + 1, i);
        v.pop_back();
       
    }

}


int main(){

    cin >> N >> M;


    go(0,1);

}

