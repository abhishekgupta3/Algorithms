#include <iostream>
using namespace std;

// TC: O(N)
void BuildTree(int *arr, int *tree, int l, int h, int treeNode) {
	// Base Case
	if (l == h) {
		tree[treeNode] = arr[l];
		return;
	}

	int mid = (l + h) / 2;
	BuildTree(arr, tree, l, mid, 2 * treeNode);
	BuildTree(arr, tree, mid + 1, h, 2 * treeNode + 1);
	tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}

// TC: O(logN)
void update(int *arr, int *tree, int l, int h, int treeNode, int idx, int value) {
	// Base Case
	if (l == h) {
		tree[treeNode] = value;
		arr[idx] = value;
		return;
	}

	int mid = (l + h) / 2;

	if (idx <= mid) update(arr, tree, l, mid, 2 * treeNode, idx, value);
	else update(arr, tree, mid + 1, h, 2 * treeNode + 1, idx, value);

	tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}
// TC: O(logN)
int range(int* tree, int l, int h, int treeNode, int left, int right) {
	// completely outside the given range
	if (h < left || l > right)return 0;

	// completely inside the given range
	if (l >= left and h <= right) return tree[treeNode];

	// partially inside or partially outside
	int mid = (l + h) / 2;
	return range(tree, l, mid, 2 * treeNode, left, right) + range(tree, mid + 1, h, 2 * treeNode + 1, left, right);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	int * tree = new int[2 * n];

	int l = 0, h = n - 1;
	int treeNode = 1;

	BuildTree(arr, tree, l, h, treeNode);
	for (int i = 1; i < 2 * n; ++i) cout << tree[i] << " ";
	cout << '\n';

	update(arr, tree, l, h, treeNode, 2, 10);
	for (int i = 1; i < 2 * n; ++i) cout << tree[i] << " ";
	cout << '\n';

	cout << range(tree, l, h, treeNode, 0, 7);

	return 0;
}