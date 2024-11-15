#include <iostream>
#include<algorithm>
#include<string>


typedef long long ll;

using namespace std;


ll DP[2][100001];
int A[2][100001];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T,n;

	cin >> T,n;

	

	while (T--){
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> A[0][i];
		for (int i = 1; i <= n; i++) cin >> A[1][i];

		DP[0][1] = A[0][1];
		DP[1][1] = A[1][1];
		DP[0][2] = A[0][2] + DP[1][1];
		DP[1][2] = A[1][2] + DP[0][1];

		for (int i = 3; i <= n; i++){
			DP[0][i] = A[0][i] + max(DP[1][i-1],DP[1][i-2]);
			DP[1][i] = A[1][i] + max(DP[0][i-1],DP[0][i-2]);
		}

		cout << max(DP[0][n],DP[1][n]) << "\n";

	}


	

	





	

	
	

	

	
	

}
	
	

	
	
	
	




	

