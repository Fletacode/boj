#include<bits/stdc++.h>

#define SIZE 262150

using namespace std;

typedef long long ll;

int N,M;
int a, b;

ll arr[100010];
ll min_tree[SIZE];
ll max_tree[SIZE];


ll init_min(int node, int st, int end) {

	if (st == end) {
		return min_tree[node] = min(min_tree[node],arr[st]);
	}

	int mid = (st + end) / 2;

	return min_tree[node] = min(init_min(node * 2, st, mid),
		init_min(node*2 + 1,mid+1,end));

}

ll init_max(int node, int st, int end) {

	if (st == end) {
		return max_tree[node] = max(max_tree[node], arr[st]);
	}

	int mid = (st + end) / 2;

	return max_tree[node] = max(init_max(node * 2, st, mid),
		init_max(node * 2 + 1, mid + 1, end));

}


ll find_min(int node, int st, int end, int left, int right) {

	if (st > right || end < left) return 1000000009;

	if (st >= left && end <= right) return min_tree[node];

	int mid = (st + end) / 2;

	
	

	return min(find_min(node * 2, st, mid, left, right),
		find_min(node * 2 + 1, mid + 1, end, left, right));


}

ll find_max(int node, int st, int end, int left, int right) {

	if (st > right || end < left) return -1;

	if (st >= left && end <= right) return max_tree[node];

	int mid = (st + end) / 2;

	return max(find_max(node * 2, st, mid, left, right),
		find_max(node * 2 + 1, mid + 1, end, left, right));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	

	
	fill(min_tree, min_tree + SIZE, 1000000009);
	fill(max_tree, max_tree + SIZE, -1);

	cin >> N >> M;


	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	init_min(1, 0, N-1);
	init_max(1, 0, N - 1);

	while (M--) {
		cin >> a >> b;
		cout << find_min(1, 0, N - 1, a - 1, b - 1) << " " << find_max(1, 0, N - 1, a - 1, b - 1) << "\n";
	}
	
}