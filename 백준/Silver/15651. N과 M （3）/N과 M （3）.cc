#include<bits/stdc++.h>

using namespace std;

int N,M;

vector<int> v;


void go(int depth){

    if (depth >= M){
        for (int i : v) cout << i << " ";
        cout << "\n";
        return;
    }
    
    for (int i = 1; i <= N; i++){
        
        v.push_back(i);
        go(depth + 1);
        v.pop_back();
       
    }

    

}


int main(){

    cin >> N >> M;


    go(0);

}

