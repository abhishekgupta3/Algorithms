// Merge Sort T.C: O(NlogN) A.S: O(N)
// ---------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

// Merge two sorted array T.C: O(N) A.S: O(N)
void Merge(int ar[], int low, int mid, int high) {
	int size = high - low + 1;
	int temp[size] = {0};
	int i = low, j = mid + 1, k = 0;

	while (i <= mid && j <= high) {
		if (ar[i] < ar[j])temp[k++] = ar[i++];
		else temp[k++] = ar[j++];
	}
	while (j <= high) temp[k++] = ar[j++];
	while (i <= mid) temp[k++] = ar[i++];

	for (int i = 0; i < size; i++) ar[low++] = temp[i];

}

// merge sort
void MergeSort(int ar[], int low, int high) {
	if (low >= high)return;

	// Divide
	int mid = low + (high - low) / 2;
	// Recurse
	MergeSort(ar, low, mid);
	MergeSort(ar, mid + 1, high);
	// Merge
	Merge(ar, low, mid, high);

	return;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int ar[] = {11, 10};
	int n = sizeof(ar) / sizeof(ar[0]);
	int low = 0, high = n - 1;
	MergeSort(ar, low, high);

	for (int i = 0; i < n; ++i) {
		cout << ar[i] << " ";
	}

	return 0;
}