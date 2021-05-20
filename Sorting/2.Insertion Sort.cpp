// insertion Sort T.C: O(N ^ 2)
// ---------------------------------------------------------
#include <iostream>
using namespace std;

void insertionSort(int ar[], int n) {

	for (int i = 0; i < n; ++i) {
		int element = ar[i], j = i - 1;
		while (j >= 0 and ar[j] > element) {
			ar[j + 1] = ar[j];
			j--;
		}

		ar[j + 1] = element;
	}

	return;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int ar[] = {15, 16, 7, 11, 11, 1, 8, 3};
	int n = sizeof(ar) / sizeof(ar[0]);

	insertionSort(ar, n);

	for (int i = 0; i < n; ++i) {
		cout << ar[i] << " ";
	}

	return 0;
}