#include<bits/stdc++.h>

#define MAX_SIZE 10000010

using namespace std;

int N;

int weight_type[7] = {1,2,5,10,20,50,100};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    
    cin >> N;

    int a,b;

    cin >> a >> b;

    for (int i = 2; i < N; i++){
        int num;
        cin >> num;

        if (a == b){
            a += num;
        } else if (a < b){
            a += num;
        } else{
            b += num;
        }
    }

    int diff = abs(a-b);
	int ans = 0;
	for (int i = 6; i >= 0; i--){
		ans += diff / weight_type[i];
		diff %= weight_type[i];
	}
	cout << ans;
}