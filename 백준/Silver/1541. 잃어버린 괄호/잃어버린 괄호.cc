#include<bits/stdc++.h>

using namespace std;

string str;

vector<int> nums;

vector<char> cals;

void split_fun(){

    string num = "";

    for (int i = 0; i < str.size(); i++){
        if (str[i] == '-' || str[i] == '+'){
            nums.push_back(stoi(num));
            num = "";
            cals.push_back(str[i]);
        } else {
            num += to_string(str[i] - '0');
        }
    }  

    nums.push_back(stoi(num)); 

}

int get_ans(){

    int total = 0;

    bool flag = false;

    for (int i = 0; i < nums.size(); i++) {
        if (flag){
            total -= nums[i];
        } else{
            total += nums[i];
        }

        if (cals[i] == '-'){
            flag = true;
        }
        
    }

    return total;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> str;

    split_fun();

    if (cals.size() == 0){
        cout << nums[0];
    } else{
        cout <<get_ans();
    }

  

}