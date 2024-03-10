#include<bits/stdc++.h>


using namespace std;

int a[5];

string s;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'M') a[0]++;
		else if (s[i] == 'O') a[1]++;
		else if (s[i] == 'B') a[2]++;
		else if (s[i] == 'I') a[3]++;
		else if (s[i] == 'S') a[4]++;
	}

	for (int i = 0; i < 5; i++) {
		if (a[i] <= 0) {
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";

}