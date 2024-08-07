#include<bits/stdc++.h>


using namespace std;

int T;
string s1, s2 , s3;

bool find_flag;

void dfs(int s1_idx, int s2_idx, int s3_idx){

    if (find_flag) return;

    if (s3_idx >= s3.size()){
        find_flag = true;
        return;
    }

    if (s1_idx < s1.size() && s1[s1_idx] == s3[s3_idx]){
        dfs(s1_idx + 1, s2_idx, s3_idx + 1);
    }

    if (s2_idx < s2.size() && s2[s2_idx] == s3[s3_idx]){
        dfs(s1_idx, s2_idx + 1, s3_idx + 1);
    }

}

bool check(){
    if (s1.size() + s2.size() != s3.size()) return false;

    int alpha[26];

    memset(alpha,0, sizeof(alpha));

    for (int i = 0; i < s1.size(); i++){
        alpha[s1[i] - 'a']++;
    }
    for (int i = 0; i < s2.size(); i++){
        alpha[s2[i] - 'a']++;
    }
    for (int i = 0; i < s3.size(); i++){
        alpha[s3[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++){
        if (alpha[i]) return false;
    }

    return true;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;

    for (int t  = 1; t <= T; t++){
        cin >> s1 >> s2 >> s3;

        find_flag = false;

        if (check()){
            

            dfs(0,0,0);

            if (find_flag){
                cout << "Data set " << t << ": yes\n";
            }else{
             cout << "Data set " << t << ": no\n";
            }
        }else{
            cout << "Data set " << t << ": no\n";
        }

        


    }

}