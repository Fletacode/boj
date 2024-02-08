#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> v1;
vector<ll> v2;

ll A[32];
int N;
ll C;

void go(int idx,int end,ll sum) {

	if (sum > C) return;

	if (idx >= end) {
		if (end == N/2) v1.push_back(sum);
		else {
			v2.push_back(sum);
		}
		return;
	}


	go(idx + 1, end,sum + A[idx]);
	go(idx + 1,end ,sum);


	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N);

	go(0, N/2,0);
	go(N / 2 , N, 0);
	
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	ll ans = 0;

	
	for (int i = 0; i < v2.size(); i++) {
		if (C - v2[i] >= 0) {
			int find_idx = 
				upper_bound(v1.begin(), v1.end(), C - v2[i]) - v1.begin();
			ans += find_idx;
		}

	}
	
	cout << ans;

}