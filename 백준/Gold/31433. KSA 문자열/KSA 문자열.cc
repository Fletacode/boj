#include<bits/stdc++.h>

using namespace std;


string input;

queue<int> q;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
   
    
    cin >> input;

    

    for (int i = 0; i < input.size(); i++){
        if (input[i] == 'K') q.push(0);
        else if (input[i] == 'S') q.push(1);
        else{
            q.push(2);
        }
        
    }
    
    int now = 0;

    int q_size = 0;

    int cnt = 0;

    while(!q.empty()){
        if (now == q.front()){
            q.pop();
            q_size++;
            now++;
            now %= 3;
        }else{
            q.pop(); cnt++;
        }
    }


    cout << cnt + (input.size() - q_size);
    


    
}