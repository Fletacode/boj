#include<bits/stdc++.h>

using namespace std;


int N, P;

int main() {
	cin >> N >> P;
	
	if (N >= 20) {
		cout << min(max(0,(P - (P / 4))), max(0,P - 2000));
	}
	else if (N >= 15) {
		cout << min(max(0,P - 2000), max(0, (P - (P / 10))));
	}
	else if (N >= 10) {
		cout << min(max(0, P - 500), max(0, (P - (P / 10))));
	}
	else if (N >= 5){
		cout << max(P - 500,0);
	}
	else {
		cout << P;
	}
}