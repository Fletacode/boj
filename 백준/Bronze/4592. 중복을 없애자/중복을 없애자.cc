#include<bits/stdc++.h>

using namespace std;



int n;
int num;

int before;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	while (true) {
		cin >> n;
		before = 0;
		if (n == 0) return 0;
		while (n--) {
			cin >> num;
			if (before == num) {
				before = num;
				continue;
			} 
			cout << num << " ";
			before = num;
		}
		cout << "$\n";
	}
	
	
	
	

}