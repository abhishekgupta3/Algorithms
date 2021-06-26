// Count of smaller numbers after self
// I/P [5 2 6 1] O/P [2 1 1 0]
// ***********************************************************************
#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

void merge(vector<pii>& arr, vector<int>&ans, int l, int mid, int h) {
	vector<pii>temp(h - l + 1);
	int p1 = l, p2 = mid + 1 , cnt = 0, k = 0;

	while (p1 <= mid && p2 <= h) {
		if (arr[p1].first <= arr[p2].first) {
			temp[k++] = {arr[p1].first, arr[p1].second};
			ans[arr[p1].second] += cnt;
			p1++;
		}
		else {
			temp[k++] = {arr[p2].first, arr[p2].second};
			cnt++;
			p2++;
		}
	}

	while (p1 <= mid) {
		ans[arr[p1].second] += cnt;
		temp[k++] = {arr[p1].first, arr[p1].second};
		p1++;
	}

	while (p2 <= h) {
		temp[k++] = {arr[p2].first, arr[p2].second};
		p2++;
	}

	// update the arr with temp
	k = 0;
	for (int i = l; i <= h; i++) {
		arr[i] = temp[k++];
	}

	return;
}

void mergeSort(vector<pii>& arr, vector<int>&ans, int l, int h) {
	if (l >= h)return;
	int mid = (l + h) >> 1;

	mergeSort(arr, ans, l, mid);
	mergeSort(arr, ans, mid + 1, h);
	merge(arr, ans, l, mid, h);

	return;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, a; cin >> n;
	vector<pii> arr(n);

	for (int i = 0; i < n; ++i)	{
		cin >> a;
		arr[i] = {a, i};
	}

	vector<int> ans(n, 0);
	mergeSort(arr, ans, 0, n - 1);

	for (int i = 0; i < n; ++i)cout << ans[i] << " ";

	return 0;
}