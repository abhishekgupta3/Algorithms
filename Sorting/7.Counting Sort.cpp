// Counting Sort: T.C: O(N+k) A.S: O(N+k)
// ----------------------------------------------------------------------
#include <iostream>
#include <algorithm>
using namespace std;

// 0 1 2 3 4 5 6 7  indices
// 1 4 1 2 7 5 2    arr
// 0 2 4 4 5 6 6 7  final cnt array
// 1 1 2 2 4 5 7    sorted ouput array

void countingSort(int ar[], int n) {

	int output[n]; // output array which stores the data in sorted order
	// k is for range of elements
	int k = *max_element(ar, ar + n);

	int cnt[k + 1] = {0}; // 0 based for also storing 0 occurences if any

	for (int i = 0; i < n; i++) cnt[ar[i]]++;
	for (int i = 1; i <= k; i++) cnt[i] += cnt[i - 1];

	for (int i = n - 1; i >= 0; i--) {
		output[cnt[ar[i]] - 1] = ar[i];
		cnt[ar[i]]--;
	}

	for (int i = 0; i < n; ++i) ar[i] = output[i];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int ar[] = {1, 4, 4, 1, 0, 1 };
	int n = sizeof(ar) / sizeof(ar[0]);

	countingSort(ar, n);

	for (int i = 0; i < n; ++i) {
		cout << ar[i] << " ";
	}

	return 0;
}