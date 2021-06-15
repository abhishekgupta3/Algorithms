#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int b[], int n, int m) {
	int gap = (n + m);
	gap = (gap / 2) + (gap % 2);

	while (gap > 0) {
		int i = 0, j = i + gap;
		while (j < (n + m)) {
			if (j < n) {
				if (a[i] > a[j])swap(a[i], a[j]);
			}
			else if (i >= n) {
				if (b[i - n] > b[j - n])swap(b[i - n], b[j - n]);
			}
			else {
				if (a[i] > b[j - n])swap(a[i], b[j - n]);
			}
			j++, i++;
		}
		gap = (gap / 2) + (gap % 2);
	}
	return;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m; cin >> n >> m;
	int a[n], b[m];
	for (int i = 0; i < n; ++i)cin >> a[i];
	for (int i = 0; i < m; ++i)cin >> b[i];

	merge(a, b, n, m);

	for (int i = 0; i < n; ++i)cout << a[i] << " ";
	for (int i = 0; i < m; ++i)cout <<  b[i] << " ";

	return 0;
}