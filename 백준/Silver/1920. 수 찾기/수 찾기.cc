#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int N,M;
vector<int> v;
vector<int> v2;

bool isFind(int target){

    int idx = lower_bound(v.begin(), v.end(), target) - v.begin();

    if (idx > v.size()-1 || idx < 0){
        return false;
    } else if (v[idx] == target){
        return true;
    } else{
        return false;
    }

}


void sol(){

    sort(v.begin(), v.end());

    for (int i : v2){
        
        if (isFind(i)){
            cout << 1 << "\n";
        } else{
            cout << 0 << "\n";
        }
    }

}


void input_fun(){
    cin >> N;
    int num;
    for (int i =0; i < N; i++){
        cin >> num;
        v.push_back(num);
    }

    cin >> M;

    for (int i = 0; i < M; i++){
        cin >> num;
        v2.push_back(num);
    }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    
    input_fun();
    sol();


}