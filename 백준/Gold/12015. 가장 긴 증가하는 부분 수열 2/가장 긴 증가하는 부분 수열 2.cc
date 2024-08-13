#include<bits/stdc++.h>


using namespace std;

int N;

int A[1000010];

vector<int> v;

int find_idx(int val){

    int st = 0;
    int end = v.size()-1;

    while(st < end){

        int mid  = (st+end) / 2;

        if (v[mid] < val){
            st = mid + 1;
        }else{
            end = mid;
        }

    }

    return end;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    v.push_back(A[0]);

    for (int i = 1; i < N; i++){
        
        if (v[v.size()-1] < A[i]){
            v.push_back(A[i]);
        }else if (v[v.size()-1] > A[i]){
            int idx = find_idx(A[i]);
            v[idx] = A[i];
        }

    }

    cout << v.size();

    

}