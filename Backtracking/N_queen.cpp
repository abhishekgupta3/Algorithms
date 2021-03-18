// N Queen

#include <bits/stdc++.h>
using namespace std;

bool board[11][11];

bool isSafe(int n, int row, int col) {
	// traversing the upper part of the column
	for (int i = row - 1; i >= 0; i--) {
		if (board[i][col] == 1)return false;
	}
	// traversing the upper left diagonal
	for (int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--) {
		if (board[i][j] == 1)return false;
	}

	// traversing the upper right diagonal
	for (int i = row - 1, j = col + 1; i >= 0 and j < n; i--, j++) {
		if (board[i][j] == 1)return false;
	}

	return true;
}

void NQueen(int n, int row) {

	// reached the end
	if (row == n) {
		// print the board
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; j++) {
				cout << board[i][j] << " ";
			}
			cout << '\n';
		}
		cout << '\n';

		return;
	}

	// traversing the column
	for (int j = 0; j < n; j++) {
		// if the given position is safe recursive call to next row
		if (isSafe(n, row, j) == true) {
			board[row][j] = 1;
			NQueen(n, row + 1); // recursive call to next row
			board[row][j] = 0; // backtrack....
		}
	}
	return;

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	memset(board, 0, sizeof board);
	NQueen(8, 0);

	return 0;

}