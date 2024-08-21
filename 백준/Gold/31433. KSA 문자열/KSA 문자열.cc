#include<bits/stdc++.h>

using namespace std;


string input;



int cal(string str,int cnt){

    queue<int> q;

    for (int i = 0; i < str.size(); i++){
        if (str[i] == 'K') q.push(0);
        else if (str[i] == 'S') q.push(1);
        else{
            q.push(2);
        }
        
    }

    
    int q_size = 0;

    while(!q.empty()){
        if (q_size % 3 == q.front()){
            q.pop();
            q_size++;
            
        }else{
            q.pop(); cnt++;
        }
    }

    cnt += abs( int( input.size() - q_size) );

    return cnt;
}




int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
   
    
    cin >> input;

    int ans = 1e9;

    ans = min(ans, cal(input,0));
    ans = min(ans, cal("K" + input, 1));
    ans = min(ans, cal( "KS" + input, 2));


    cout << ans;
    
}