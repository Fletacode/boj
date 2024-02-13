#include<bits/stdc++.h>


using namespace std;

string s1, s2;
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> s1;
	cin >> N;
	int ans = 0;
	while (N--) {
		cin >> s2;
		if (s1 == s2) ans++;
	}
	cout << ans;


}