#include<bits/stdc++.h>


using namespace std;

int N;
string s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	int num;
	int ans = 0;
	while (N--) {
		cin >> s; 
		if (s.size() == 3) num = stoi(s.substr(2, 1));
		else if (s.size() == 4) num = stoi(s.substr(2, 2));
		else {
			num = stoi(s.substr(2, 3));
		}

		if (num <= 90) ans++;
		
	}

	cout << ans;

}