#include<bits/stdc++.h>

using namespace std;

int N;
int num;

int ans = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;



	for (int i = 0; i < N; i++) {
		cin >> num;
		ans += num;
		ans += 8;
	}

	ans -= 8;

	cout << (ans / 24) << " " << ans % 24;

}