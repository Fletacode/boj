#include<bits/stdc++.h>


using namespace std;

int N,M;

string str;
deque<string> dq;
vector<string> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> str;
    cin >> M;

    for (int i = 0; i < str.size(); i++){
        string temp = "";
        temp += str[i];
        v.push_back(temp);
    }

    string input;
    

    while(M--){
        cin >> input;
        if (input == "L"){
            if (!v.size()) continue;
            dq.push_back(v.back());
            v.pop_back();
        }else if (input == "D"){
            if (!dq.size()) continue;
            v.push_back(dq.back());
            dq.pop_back();
        }else if (input == "B"){
            if (!v.size()) continue;
            v.pop_back();
        }else if (input == "P"){
            string add_s = "";
            cin >> add_s;
            v.push_back(add_s);
            
        }
        //cout << s << "\n";
    }
     string ans = "";

    for (int i = 0; i < v.size(); i++){
        ans += v[i];
    }

    for (int i = dq.size()-1; i >= 0; i--){
        ans += dq[i];
    }

    cout << ans;

   

    

    
   
}