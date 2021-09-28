// Suduko Solver

#include <bits/stdc++.h>
using namespace std;

int grid[9][9];

bool isValid(int row, int col, int num) {

	// checking in row & column whether the num is present or not
	for (int i = 0; i < 9; i++) {
		if (grid[i][col] == num || grid[row][i] == num)return false;
	}

	// checking in 3 X 3 small grid, start of small grid X is (row / 3) * 3
	int startx = (row / 3) * 3, starty = (col / 3) * 3;

	for (int i = startx; i < startx + 3; i++) {
		for (int j = starty; j < starty + 3; j++) {
			if (grid[i][j] == num)return false;
		}
	}

	return true;
}

bool solveSuduko( int row, int col) {

	// reached end
	if (row >= 9) return true;

	// when col becomes greater than 9 -> do col to 0 and row+1
	if (col >= 9) return solveSuduko(row + 1, 0);

	if (grid[row][col] != 0) {
		return solveSuduko( row , col + 1);
	}

	// picking any valid num from 1 to 9

	for (int k = 1; k <= 9; k++) {
		if (isValid( row, col, k)) {
			grid[row][col] = k;
			if (solveSuduko( row , col + 1) == true) {
				return true;
			}
		}
	}
	// if solveSuduko(row,col+1) above returned false we return false
	grid[row][col] = 0;

	return false;
}

int main() {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> grid[i][j];
		}
	}

	cout << solveSuduko(0 , 0) << endl;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << grid[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}