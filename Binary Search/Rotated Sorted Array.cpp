// Search in Rotated sorted array

#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &arr, int n, int B) {

	int l = 0, h = n - 1, mid;

	while (l <= h) {
		mid = (l + h) >> 1;
		if (arr[mid] == B)return mid;

		// left half sorted
		if (arr[l] <= arr[mid]) {
			if (arr[l] <= B and arr[mid] >= B)h = mid - 1;
			else l = mid + 1;
		}
		// right half sorted
		else {
			if (arr[h] >= B and arr[mid] <= B)l = mid + 1;
			else h = mid - 1;
		}
	}

	return -1;
}


int main() {
	int n, k; cin >> n >> k;
	vector<int>arr(n);
	for (int i = 0; i < n; ++i)cin >> arr[i];
	cout << search(arr, n, k);

	return 0;
}