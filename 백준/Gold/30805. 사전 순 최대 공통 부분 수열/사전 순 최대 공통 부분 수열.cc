#include<bits/stdc++.h>

using namespace std;


int N,M;

vector<int> a;

vector<int> b;

vector<int> ans;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++){
        int num;
        cin >> num;
        a.push_back(num);
    }

    cin >> M;

    for (int i = 0; i < M; i++){
        int num;
        cin >> num;
        b.push_back(num);
    }



    while(true){
        bool flag = true;

        int a_idx, b_idx, max_a, max_b = 0;

        while(!a.empty() && !b.empty()){
            max_a = *max_element(a.begin(), a.end());
            a_idx = max_element(a.begin(), a.end()) - a.begin();

            max_b = *max_element(b.begin(), b.end());
            b_idx = max_element(b.begin(), b.end()) - b.begin();

            if (max_a == max_b) break;
            else if (max_a > max_b) a.erase(a.begin() + a_idx);
            else{
                b.erase(b.begin() + b_idx);
            }

        }

        if (a.empty() || b.empty()) break;

        ans.push_back(max_a);

        a.erase(a.begin(), a.begin() + a_idx + 1);
        b.erase(b.begin(), b.begin() + b_idx + 1);
        
        
    }
    

    cout << ans.size() << "\n";

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }


}