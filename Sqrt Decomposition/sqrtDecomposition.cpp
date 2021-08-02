// Sqrt Decomposition
// Range Sum Query (RSQ)
#include <bits/stdc++.h>
using namespace std;

// T.C: O(sqrt(n))
int query(int arr[], int blocks[], int l, int r, int n, int rn) {
	int sum = 0;

	while(l <= r) {
		if(l % rn == 0 && l + rn <= r) {
			sum += blocks[l / rn];
			l += rn;
		} 
		else {
			sum += arr[l];
			l++;
		}
	}

	return sum;
}

// T.C: O(1)
void update(int arr[], int blocks[], int idx, int val, int n, int rn) {
	blocks[idx / rn] += val - arr[idx];
	arr[idx] = val;
}

void print(int blocks[], int rn) {
	// Print blocks
	for(int i = 0; i <= rn; ++i) {
		cout << blocks[i] << " ";
	}

	cout << '\n';
}

int main(){

	int n; cin >> n;
	int arr[n]; 
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int rn = sqrt(n); //sqrt of n

	int blocks[rn + 1] = {0};

	//Preprocess
	int j = -1;
	for(int i = 0; i < n; ++i) {
		if(i % rn == 0) j++;
		blocks[j] += arr[i]; 
	}

	print(blocks, rn);

	// Update
	int idx, val; cin >> idx >> val;
	update(arr, blocks, idx - 1, val, n, rn);

	// Query
	int l, r; cin >> l >> r;
	cout << query(arr, blocks, l - 1, r - 1, n, rn) << '\n';



	return 0;
}