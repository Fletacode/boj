#include<bits/stdc++.h>

using namespace std;




int N;

int divdeMaxSum(vector<int> &v, int st,int end ){

    if (st == end) return v[st];

    int mid = (st+end) / 2;

    int left = INT_MIN; int right = INT_MIN;
    int sum = 0;

    for (int i = mid; i >= st; i--){
        sum += v[i];
        left = max(left, sum); 
    }

    sum  = 0;

    for (int i = mid + 1; i <= end; i++){
        sum += v[i];
        right = max(right, sum);
    }

    int single = max(divdeMaxSum(v,st, mid ) , divdeMaxSum(v, mid + 1, end));

    return max(single, left + right);

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    vector<int> v;

    for (int i = 0; i < N; i++){
        int num;
        cin >> num; v.push_back(num);
    }

    cout << divdeMaxSum(v,0,N-1);

}