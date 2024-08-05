#include <bits/stdc++.h>

using namespace std;


int N;

bool ans[1010];

vector<pair<string, pair<int,int> > > v;

bool check(int i){
    string s = to_string(i);
        int first = s[0] - '0';
        int second = s[1] - '0';
        int third = s[2] - '0';

        if (first == 0 || second == 0 || third == 0) return false;

        if (first == second || first == third || second == third) return false;

        return true;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    
   
    

    cin >> N;

    int snum, bnum;
    string input;


    while(N--){
        cin >> input >> snum >> bnum;

        v.push_back({input, {snum, bnum }});

        

    }

    for (int i = 123; i <= 987; i++){
        if (!check(i)) continue;

        bool doit = true;
        
        for (pair<string,pair<int,int>> p : v){
            string input = p.first;
            int snum = p.second.first;
            int bnum = p.second.second;

            string s = to_string(i);
            int scnt = 0;
            int bcnt = 0;

            for (int j = 0; j < 3; j++){

                if (input[j] == s[j]){
                    scnt++;
                    continue;
                } 

                for (int k = 0; k < 3; k++){
                    if (input[j] == s[k]) bcnt++;
                }
            }

            if (snum != scnt || bnum != bcnt){
                doit = false;
                break;
            } 

        }

        if (doit) ans[i] = true;

            

            

            

        }

    int ans_num = 0;

    for (int i = 123; i <= 987; i++){
        if (ans[i]) ans_num++;
    }

    cout << ans_num;

   

}