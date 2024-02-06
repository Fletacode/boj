#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;

int A[110];
ll dp[110][21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	dp[1][A[1]] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j]) {
				if (j + A[i] <= 20 && j + A[i] >= 0) {
					dp[i][j + A[i]] += dp[i - 1][j];
				} 
				if (j - A[i] >= 0 && j - A[i] <= 20) {
					dp[i][j - A[i]] += dp[i - 1][j];
				} 
			}
		}
	}

	int ans = 0;

	

	cout << dp[N-1][A[N]];


}