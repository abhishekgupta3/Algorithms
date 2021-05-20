// Bubble Sort T.C: O(N ^ 2)
// ---------------------------------------------------------
#include <iostream>
using namespace std;

void BubbleSort(int ar[], int n) {

	for (int i = 0; i < n - 1; ++i) {
		bool flag = false;
		for (int j = 0; j < n - i - 1; ++j) {
			if (ar[j] > ar[j + 1]) {
				// swap
				int temp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = temp;
				flag = true;
			}
		}
		// array is sorted
		if (flag == false)return;
	}

	return;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int ar[] = {11, 12, 13};
	int n = sizeof(ar) / sizeof(ar[0]);

	BubbleSort(ar, n);

	for (int i = 0; i < n; ++i) {
		cout << ar[i] << " ";
	}

	return 0;
}