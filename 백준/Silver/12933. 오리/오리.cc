#include<bits/stdc++.h>


using namespace std;


string s;

int cnt[2510];
bool visited[2510];


char A[5] = {'q','u','a','c','k'};

int ans = 1;

bool find_quack(int st,int next){

    

    for (int i = st; i < s.size(); i++){
        if (s[i] == A[next] && !visited[i]){
            next++;
        }
        if (next == 5) return true;
    }

    
    
    return false;
    
    
}

void plus_quack(int st, int next){
    for (int i = st; i < s.size(); i++){
        if (s[i] == A[next] && !visited[i]){
            visited[i] = true;
            next++;
        }
        cnt[i]++;
        if (next == 5) return;
    }

    
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;

    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'q'){
            if (find_quack(i,0)){
                //cout << i << " ";
                plus_quack(i,0);
            }else{
                cout << -1;
                return 0;
            }
        }
    
    }

    int ans = -1;

    

    for (int i = 0; i < s.size(); i++){
        ans = max(ans, cnt[i]);
        //cout << visited[i] << " ";
    }

    for (int i = 0; i < s.size(); i++){
        if (!visited[i]){
            cout << -1;
            return 0;
        }
    }

    cout << ans;
    
   

}