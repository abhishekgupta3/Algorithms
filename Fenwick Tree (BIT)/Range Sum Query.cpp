/*
** Fenwick Tree: Range Sum Query
*/

#include <iostream>

// O(logN)
void update(int *tree, int i, int val, int n) {
	while(i <= n) {
		tree[i] += val;
		i += i & (-i);
	}
}

// O(NlogN)
void build(int *tree, int *arr, int n) {
	for(int i = 0; i < n; i++) {
		update(tree, i + 1, arr[i], n);
	}
}

// O(logN)
int query(int *tree, int i) {
	int sum = 0;
	while(i > 0) {
		sum += tree[i];
		i -= i & (-i); // Removing right most set bit
	}
	return sum;
}

int main() {

	int arr[] = {2, 5, 6, 1, 4};
	int n = 5;
	int tree[n + 1] = {};

	build(tree, arr, n);

	for(auto x: tree) std :: cout << x << " ";
	std :: cout << '\n';
	
	int l, r; std :: cin >> l >> r;

	std :: cout << query(tree, r) - query(tree, l - 1);

	return 0;
}