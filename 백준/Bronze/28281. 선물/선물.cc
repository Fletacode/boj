#include<bits/stdc++.h>


using namespace std;

typedef long long ll;

int N,X;

vector<ll> v;

ll ans = LONG_MAX;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> X;

	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}



	for (int i = 0; i < N - 1; i++) {
		
		

		ans = min(ans, (v[i]* X) + (v[i+1] * X ) );

		
	}

	cout << ans;
}