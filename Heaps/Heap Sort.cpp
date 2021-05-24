#include <bits/stdc++.h>
using namespace std;

// down heapify
void heapify(int arr[], int n, int parentIndex) {

	int leftChild = 2 * parentIndex + 1, rightChild = 2 * parentIndex + 2;

	while (leftChild < n) {
		int minIndex = parentIndex;
		if (arr[leftChild] < arr[minIndex])minIndex = leftChild;
		if (arr[rightChild] < arr[minIndex])minIndex = rightChild;

		if (minIndex == parentIndex)break;

		swap(arr[parentIndex], arr[minIndex]);
		parentIndex = minIndex;
		leftChild = 2 * parentIndex + 1, rightChild = 2 * parentIndex + 2;
	}
	return;
}

void buildHeap(int arr[], int n) {
	// first non leaf node
	int index = (n - 2) / 2;

	for (int i = index; i >= 0; i--) {
		heapify(arr, n, i);
	}

	return;
}

void HeapSort(int arr[], int n) {

	buildHeap(arr, n);

	int size = n;

	while (size > 1) {

		swap(arr[0], arr[size - 1]);
		size--;
		heapify(arr, size, 0);
	}

	return;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[] = {5, 1, 2, 0, 8};
	int n = sizeof(arr) / sizeof(arr[0]);

	HeapSort(arr, n);

	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}

	return 0;
}