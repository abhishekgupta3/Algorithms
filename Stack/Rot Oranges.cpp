// Rot Oranges
// 0 empty cell
// 1 fresh oranges
// 2 rotten oranges
// --------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

// T.C: O(N*M)
int RotOrange(int** arr, int r, int c) {

	queue<pair<pii, int>>q; // (i,j),d
	// inserting all rotten oranges in queue
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (arr[i][j] == 2)q.push({{i, j}, 0});
		}
	}

	int dx[] = {1, -1};
	int dy[] = {1, -1};

	int max_time = 0;
	//BFS
	while (!q.empty()) {
		auto temp = q.front();
		int i = temp.first.first, j = temp.first.second, depth = temp.second;
		if (depth > max_time)max_time = depth;
		q.pop();

		// traversing in all 4 directions
		for (int k = 0; k < 2; k++) {
			if (i + dx[k] < r and i + dx[k] >= 0 and arr[i + dx[k]][j] == 1) {
				q.push({{i + dx[k], j}, depth + 1});
				arr[i + dx[k]][j] = 2;
			}
			if (j + dy[k] < c and j + dy[k] >= 0 and arr[i][j + dy[k]] == 1) {
				q.push({{i, j + dy[k]}, depth + 1});
				arr[i][j + dy[k]] = 2;

			}
		}
	}

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (arr[i][j] == 1)return -1;
		}
	}

	return max_time;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output999.txt", "w", stdout);
#endif
	int r, c; cin >> r >> c;
	int ** arr = new int*[r];

	for (int i = 0; i < r; ++i) {
		arr[i] = new int[c];
		for (int j = 0; j < c; ++j) {
			cin >> arr[i][j];
		}
	}

	cout << RotOrange(arr, r, c) << '\n';

	return 0;
}