#include<iostream>
#include<unordered_set>

using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unordered_set<int> s;

	int N,M,num;
	cin >> N;

	for (int i = 0; i < N; i++){
		
		cin >> num;
		s.insert(num);
	}


	cin >> M;
	for (int i = 0; i < M; i++){
	
		cin >> num;
		
		if (s.find(num) == s.end()) cout << 0 <<" ";
		else{ cout << 1 <<" ";}
	}
	



	

}
