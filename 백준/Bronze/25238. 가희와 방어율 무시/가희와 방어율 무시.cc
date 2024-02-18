#include<bits/stdc++.h>

using namespace std;

int a, b;

int main() {

	cin >> a >> b;

	double num = ( a * 100 - (a * b) ) / 100;

	if (num >= 100.0) {
		cout << 0;
	}
	else {
		cout << 1;
	}

	
}