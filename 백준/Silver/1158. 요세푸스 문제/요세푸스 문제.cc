#include<bits/stdc++.h>

using namespace std;

int N,K;

queue<int> q;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    

    for (int i = 0; i < N; i++){    
        q.push(i+1);
    }

    vector<int> v;

    while(!q.empty()){
        
        for (int i = 0; i < K-1; i++){
            q.push(q.front());
            q.pop();
        }

        v.push_back(q.front());
        q.pop();

    }


    cout << "<";

    for (int i = 0; i < v.size()-1; i++){
        cout << v[i] << ", ";
    }

    cout << v[v.size()-1] << ">";



    

    

   

  
   
    
    

}