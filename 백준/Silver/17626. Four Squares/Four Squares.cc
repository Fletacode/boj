#include <iostream>

#include <algorithm>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;

int N;



int DP[50001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> v;
	v.push_back(1);
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 3;
	DP[4] = 1;
	v.push_back(4);
	int num = 3;
	for (int i = 5; i <= 50000; i++){
		int n = pow(num,2);
		if (i% n == 0){
			num++;
			DP[i] = 1;
			v.push_back(i);
		}else{
			int min_val = INT_MAX;
			for (int item : v){
				min_val = min(DP[i-item],min_val);
			}
			DP[i] = min_val + 1;
		}
	}

	cout << DP[N];
	
	


}