#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int A[1010];
int n;
int len = 1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    cin >> A[0];
    int num;
    for (int i = 1; i < n; i++){
        cin >> num;
        auto find_num = lower_bound(A, A+len, num);
        if (find_num == A+len){
            len++;
        }
        *find_num = num;
    }

    cout << len;


    

}