#include <bits/stdc++.h>
using namespace std;


int k,n;

string endP;
string startP = "ABCDEFGHIJKLNMOPQRSTUVWXYZ";

string ladder[1010];

int lost_point;
char start_ladder[1010];
char end_ladder[1010];

int down(int la,int st, int end){

    int now = la;

    for (int i = st; i < end; i++){
        if (now-1 >= 0 && ladder[i][now-1] == '-'){
            now--;
        } else if (ladder[i][now] == '-') {
            now++;
        } 
    }
    
    return now;
}


string fail(){
    string str = "";
    for (int i = 0; i < k-1; i++){
        str += "x";
    }
    return str;
}


string sol(){

    for (int i = 0; i < k; i++){
        int end = down(i,0,lost_point);
        start_ladder[end] = i + 'A';
    }
  
    for (int i = 0; i < k; i++){
        int end = down(i,lost_point+1,n);
        end_ladder[i] = endP[end];
    }
    //cout << down(3,lost_point+1,n) << "\n";

    string ans = "";

    for (int i = 0; i < k-1; i++){
        if (start_ladder[i] == end_ladder[i]){
            ans += "*";
        } else if (start_ladder[i] == end_ladder[i+1]){
            ans += "-";
        } else if (i-1 >= 0 && start_ladder[i] == end_ladder[i-1]){
            ans += "*";
        } else {
            return fail();
        }
    }

    return ans;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> k >> n;

    cin >> endP;
    for (int i = 0; i < n; i++){
        cin >> ladder[i]; 
        if (ladder[i][0] == '?') lost_point = i;
    }
    


    cout << sol() << "\n";


    /*

    for (int i = 0; i < k; i++){
        cout << start_ladder[i] << " ";
    }

    cout << "\n";

    for (int i = 0; i < k; i++){
        cout << end_ladder[i] << " ";
    }
    */
   
    
}