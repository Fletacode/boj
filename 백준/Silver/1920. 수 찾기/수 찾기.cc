#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int N,M;
vector<int> v;
vector<int> v2;

int isFind(int target){

    int st = 0;
    int end = v.size()-1;

    while(st <= end){
        int mid = (st+end) / 2;

        if (target > v[mid]){
            st = mid + 1;
        } else if (target < v[mid]){
            end = mid - 1;
        } else{
            return true;
        }

    }

    return false;
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