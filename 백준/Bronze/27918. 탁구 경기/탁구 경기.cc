#include<bits/stdc++.h>


using namespace std;

int N;

char c;

int x, y;

int main() {
	ios_base::sync_with_stdio(false);


	cin >> N;

	while (N--) {
		cin >> c;
		if (c == 'D') x++;
		else if (c == 'P') y++;

		if (abs(x - y) >= 2) {
			cout << x << ":" << y;
			return 0;
		}
	}

	cout << x << ":" << y;


}