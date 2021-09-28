// Inversion Count: A pair forms inversion when i<j and arr[i]>arr[j]
// -------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

// Merge two sorted array T.C: O(N) A.S: O(N)
int Merge(int ar[], int low, int mid, int high) {
	int size = high - low + 1, inv_cnt = 0;
	int temp[size] = {0};
	int i = low, j = mid + 1, k = 0;

	while (i <= mid && j <= high) {
		if (ar[i] <= ar[j])temp[k++] = ar[i++];
		else temp[k++] = ar[j++], inv_cnt += mid - i + 1;
	}
	while (j <= high) temp[k++] = ar[j++];
	while (i <= mid) temp[k++] = ar[i++];

	for (int i = 0; i < size; i++) ar[low++] = temp[i];
	return inv_cnt;
}

// merge sort
int MergeSort(int ar[], int low, int high) {
	if (low >= high)return 0;

	// Divide
	int mid = low + (high - low) / 2;
	// Recurse
	int x = MergeSort(ar, low, mid);
	int y = MergeSort(ar, mid + 1, high);
	// cross inversion
	int z = Merge(ar, low, mid, high);

	return x + y + z;
}

int main() {

	int ar[] = { 11, 9};
	int n = sizeof(ar) / sizeof(ar[0]);
	int low = 0, high = n - 1;
	cout << MergeSort(ar, low, high) << '\n';

	for (int i = 0; i < n; ++i) {
		cout << ar[i] << " ";
	}

	return 0;
}