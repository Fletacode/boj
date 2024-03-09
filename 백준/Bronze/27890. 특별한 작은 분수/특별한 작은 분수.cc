#include<bits/stdc++.h>

using namespace std;

int height,N;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> height >> N;


	while (N--) {
		if (height % 2 == 0) {
			height = (height / 2) ^ 6;
		}
		else {
			height = (height * 2) ^ 6;
		}
	}

	cout << height;

}