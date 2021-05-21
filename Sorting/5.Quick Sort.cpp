// Quick Sort -> Worst T.C: O(N ^ 2)
// ---------------------------------------------------------
#include <iostream>
using namespace std;

void quickSort(int ar[], int n) {

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int ar[] = {15, 16, 7, 11, 11, 1, 8, 3};
	int n = sizeof(ar) / sizeof(ar[0]);

	quickSort(ar, n);

	for (int i = 0; i < n; ++i) {
		cout << ar[i] << " ";
	}

	return 0;
}