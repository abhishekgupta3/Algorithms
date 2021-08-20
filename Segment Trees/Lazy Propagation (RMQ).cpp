// Range Minimum Query: Range Updates
#include <iostream>

void buildTree(int* tree, int* arr, int l, int h, int treeIdx) {
	if(l == h) {
		tree[treeIdx] = arr[l];
		return;
	}

	int mid = (l + h) >> 1;
	buildTree(tree, arr, l, mid, 2 * treeIdx);
	buildTree(tree, arr, mid + 1, h, 2 * treeIdx + 1);

	tree[treeIdx] = std :: min(tree[2 * treeIdx], tree[2 * treeIdx + 1]);
}

void updateRange(int* tree, int* lazy, int start, int end, int inc, int treeIdx, int l, int h){
	if(l > h) return;
	
	// update if lazy updates remaining
	if(lazy[treeIdx] != 0) {
		tree[treeIdx] += lazy[treeIdx];

		// if not a leaf node, propagate lazy updates
		if(l != h) {
			lazy[2 * treeIdx] += lazy[treeIdx];
			lazy[2 * treeIdx + 1] += lazy[treeIdx];
		}

		// reset current node's lazy
		lazy[treeIdx] = 0;
	}

	// complete overlap
	if(l >= start && h <= end) {

		tree[treeIdx] += inc;

		// if not a leaf node, propagate lazy updates
		if(l != h) {
			lazy[2 * treeIdx] += inc;
			lazy[2 * treeIdx + 1] += inc;
		}
		return;
	}

	// no overlap
	if(start > h || end < l) return;

	// partial overlap
	int mid = (l + h) >> 1;

	updateRange(tree, lazy, start, end, inc, 2 * treeIdx, l, mid);
	updateRange(tree, lazy, start, end, inc, 2 * treeIdx + 1, mid + 1, h);

	tree[treeIdx] = std :: min(tree[2 * treeIdx], tree[2 * treeIdx + 1]);
	return;
}

int main(){

	int arr[] = {1, 3, -2, 4};
	int n = sizeof(arr) / sizeof(arr[0]);
	int tree[2 * n] = {};

	buildTree(tree, arr, 0, n - 1, 1);

	int lazy[2 * n] = {};

	updateRange(tree, lazy, 0, 3, 3, 1, 0, n - 1);

	for(int i = 1; i < 2 * n; i++) std :: cout << tree[i] << " ";
	std :: cout << '\n';
	for(int i = 1; i < 2 * n; i++) std :: cout << lazy[i] << " ";

	return 0;
}