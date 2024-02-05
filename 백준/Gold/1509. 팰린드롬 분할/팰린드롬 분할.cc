#include<iostream>
#include<string>
#include<climits>
#include<cstring>

using namespace std;

string s;

bool A[2501][2501];
char String[2501];
int DP[2501];

void makepal(){

	for (int i = 1; i <= s.size(); i++){
		A[i][i] = true;
	}

	for (int i = 1; i < s.size(); i++){
		if (String[i] == String[i+1]){
			A[i][i+1] = true;
		}
	}

	for (int len = 3; len <= s.size(); len++){
		for (int st = 1; st + len -1 <= s.size(); st++){
			int e = st + len -1;
			if (String[st] == String[e] && (A[st+1][e-1] || st+1 == e-1) ){
				A[st][e] = true;
			}
		}
	}


}

void getmin(){


	for (int e = 3; e <= s.size(); e++){
		for (int st = 1; st <= e; st++){
			if (A[st][e]){
				DP[e] = min (DP[e] , DP[st-1] + 1);
			}
		}
	}

}





int main()
{
	cin >> s;
	
	for (int i = 0; i < s.size(); i++){
		String[i+1] = s[i];
	}

	makepal();

	for (int i = 1; i <= s.size(); i++){
		DP[i] = INT_MAX;
	}

	DP[1] = 1;
	if (A[1][2]) DP[2] = 1;
	else{
		DP[2] = 2;
	}


	getmin();

	

	cout << DP[s.size()];

	
}