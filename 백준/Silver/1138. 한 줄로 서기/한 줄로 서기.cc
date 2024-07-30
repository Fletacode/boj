#include<bits/stdc++.h>


using namespace std;


int N;

vector<int> v;

int A[12];

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);

    cin >> N;
    
    for (int i = 1; i <= N; i++){
        cin >> A[i];
    }

    v.push_back(N);

    for (int i = N-1; i > 0; i--){

        int size = A[i];

        vector<int> temp;

        while(v.size() > size){
            temp.push_back(v[v.size()-1]);
            v.pop_back();
        }

        v.push_back(i);

        while(!temp.empty()){
            v.push_back(temp.back());
            temp.pop_back();
        }

        temp.clear();

    }

    for (int i : v){
        cout << i << " ";
    }




}