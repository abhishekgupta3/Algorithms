// Quick Sort -> Worst T.C: O(N ^ 2)
// ---------------------------------------------------------
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

// Hoare's Partition
int Hoare(int arr[], int l, int h) {
	int pivot = arr[l]; //first element
	int i = l - 1, j = h + 1;

	while (true) {
		do {
			i++;
		} while (arr[i] < pivot);

		do {
			j--;
		} while (arr[j] > pivot);

		if (i >= j)return j;
		swap(arr[i], arr[j]);
	}
}

void quickSort(int ar[], int l, int h) {
	// base case
	if (l >= h)return;
	int idx = lomuto(ar, l, h);

	quickSort(ar, l, idx - 1);
	quickSort(ar, idx + 1, h);
}

int main() {

	int ar[] = {1, 3, 7, 16, 11, 15, 11, 9, 8, 0};
	int n = sizeof(ar) / sizeof(ar[0]);
	quickSort(ar, 0, n - 1);

	for (int i = 0; i < n; ++i) {
		cout << ar[i] << " ";
	}

	return 0;
}