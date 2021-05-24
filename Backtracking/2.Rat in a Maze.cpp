// Rat in a Maze
#include <bits/stdc++.h>
using namespace std;
#define n 4

void RatinaMaze(bool input[n][n], bool solution[n][n], int row, int col) {

	if (row == n - 1 and col == n - 1) {

		solution[row][col] = 1;

		//  reached end print solution matrix
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << solution[i][j] << " ";
			}
			cout << '\n';
		}
		cout << '\n';

		solution[row][col] = 0;
		return;
	}

	// base case
	if (row >= n or col >= n or input[row][col] == 0)return;

	solution[row][col] = 1;

	RatinaMaze(input, solution,  row + 1, col); // down
	RatinaMaze(input, solution,  row, col + 1); // right

	solution[row][col] = 0; //backtrack...

	return;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	bool input[n][n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input[i][j];
		}
	}

	bool solution[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			solution[i][j] = 0;
		}
	}

	RatinaMaze(input, solution,  0 , 0);

	return 0;

}