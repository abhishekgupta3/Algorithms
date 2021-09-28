// Quick Select: Kth Smallest
// T.C: Worst: O(n^2) Average: O(N) A.S: O(logN) due to recursive call stack
// *********************************************************************************

#include <iostream>
using namespace std;

// Lomuto Partition
int lomuto(int arr[], int l, int h) {
	int pivot = arr[h]; // always at last
	int i = l, j = l - 1;

	while (i < h) {
		if (arr[i] <= pivot) {
			j++;
			swap(arr[i], arr[j]);
		}
		i++;
	}

	// pivot to correct position
	swap(arr[j + 1], arr[h]);
	return j + 1;
}

int kthSmallest(int arr[], int l, int h, int k) {
	if (l == h) {
		if (k == 1)return arr[l];
		else return -1;
	}
	int idx = lomuto(arr, l, h);
	int pos = idx - l + 1;
	if (pos == k)return arr[idx];
	if (pos > k)return kthSmallest(arr, l, idx - 1, k);
	else return kthSmallest(arr, idx + 1, h, k - pos);
}


int main() {

	int ar[] = {1, 3, 7, 16, 11, 15, 11, 9, 8, 0};
	int n = sizeof(ar) / sizeof(ar[0]);
	int k = 5;
	cout << kthSmallest(ar, 0, n - 1, k) << '\n';

	for (int i = 0; i < n; ++i) {
		cout << ar[i] << " ";
	}

	return 0;
}