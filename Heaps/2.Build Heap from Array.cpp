#include <bits/stdc++.h>
using namespace std;

// Optimized O(N)
void buildHeap(int arr[], int n) {
	// first non leaf node
	int index = (n - 2) / 2;

	for (int i = index; i >= 0; i--) {
		int parentIndex = i;
		int leftChild = 2 * parentIndex + 1, rightChild = 2 * parentIndex + 2;

		// down heapify
		while (leftChild < n) {
			int minIndex = parentIndex;
			if (arr[leftChild] < arr[minIndex])minIndex = leftChild;
			if (arr[rightChild] < arr[minIndex])minIndex = rightChild;

			if (minIndex == parentIndex)break;

			swap(arr[parentIndex], arr[minIndex]);
			parentIndex = minIndex;
			leftChild = 2 * parentIndex + 1, rightChild = 2 * parentIndex + 2;
		}
	}

	return;
}


int main() {

	int arr[] = {5, 8, 2, 0, 1};
	int n = sizeof(arr) / sizeof(arr[0]);

	buildHeap(arr, n);
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}

	return 0;
}