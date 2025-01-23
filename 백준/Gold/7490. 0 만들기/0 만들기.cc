#include<bits/stdc++.h>


using namespace std;

long long T,N;
vector<string> ans;

int cal(string str) {
    int sum = 0;

    int flag = 0; // 0 +, 1 -

    string now = "1";

    for (int i = 1; i < str.size()-1; i++){
        if (str[i] == ' '){
            i++;
            now += to_string(str[i] - '0');
        } else if (str[i] == '+') {
            if (!flag) sum += stoi(now);
            else {
                sum -= stoi(now);
            }
            i++;
            now = to_string(str[i] -'0');
            flag = 0;
        } else {
            if (!flag) sum += stoi(now);
            else {
                sum -= stoi(now);
            }
            i++;
            now = to_string(str[i]-'0');
            flag = 1;
        }
    }

    if (!flag) sum += stoi(now);
    else {
        sum -= stoi(now);
    }
   
    return sum;
}

void go(int now, string str){

    if (now >= N){
        if (cal(str) == 0){
            ans.push_back(str);
        }
        return;
    }

    go(now + 1, str + "+" + to_string(now+1));
    go(now + 1, str + "-" + to_string(now +1));
    go(now + 1, str + " " + to_string(now+1));
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;
    while(T--) {
        ans.clear();
        cin >> N;
        go(1,"1");
        sort(ans.begin(), ans.end());
        for (string s : ans){
            cout << s << "\n";
        }
        cout << "\n";
    }


    

}