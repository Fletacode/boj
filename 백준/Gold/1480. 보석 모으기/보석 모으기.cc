#include<bits/stdc++.h>


using namespace std;

int N, M, C;
vector<int> v;
int dp[12][21][(1 << 13)];


int go(int m,int visited, int c,int depth) {

	if (m > M || c > C) return 0;

	if (m == M && c == C) {
		return depth;
	}

	int &ret = dp[m][c][visited];

	if (ret >= 1) return ret;

	for (int i = 0; i < v.size(); i++) {
		if ((visited & (1 << i))) continue;

		if (c + v[i] > C) {
			dp[m+1][v[i]][visited | (1 << i)]
				= go(m + 1, visited | (1 << i), v[i], depth + 1);
		}else {
			dp[m][c+v[i]][visited | (1 << i)] =
				go(m, visited | (1 << i), c + v[i], depth + 1);
		}
	}

	return depth;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> C;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	
	go(1, 0, 0, 0);

	int ans = 0;

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= C; j++) {
			for (int k = 1; k < (1 << N); k++) {
				if (dp[i][j][k]) ans = max(ans, dp[i][j][k]);
			}
		}
	}

	

	cout << ans;

}