// Selection Sort T.C: O(N ^ 2)
// ---------------------------------------------------------
#include <iostream>
using namespace std;

void SelectionSort(int ar[], int n) {

	for (int i = 0; i < n - 1; ++i) {
		int min_idx = i;
		for (int j = i + 1; j < n; ++j) {
			if (ar[j] < ar[min_idx])min_idx = j;
		}
		// swap ar[min_idx] and ar[i]
		int temp = ar[i];
		ar[i] = ar[min_idx];
		ar[min_idx] = temp;
	}

	return;
}

int main() {

	int ar[] = {15, 12, 1, 1, 15, 16, 7, 11, 11, 1, 8, 38, 3};
	int n = sizeof(ar) / sizeof(ar[0]);

	SelectionSort(ar, n);

	for (int i = 0; i < n; ++i) {
		cout << ar[i] << " ";
	}

	return 0;
}