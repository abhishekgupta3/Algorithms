// Stacks: Celebrity Problem T.C: O(N)
#include <bits/stdc++.h>
using namespace std;

int Celebrity(vector<vector<int>>& arr, int n) {

	stack<int> st;
	for (int i = 0; i < n; ++i)	st.push(i);

	while (st.size() > 1) {
		int a = st.top(); st.pop();
		int b = st.top(); st.pop();

		// if a knows b, a can't be a celebrity
		// if a doesnt knows b, b can't be a celebrity

		if (arr[a][b] == 1) st.push(b);
		else st.push(a);

	}

	// checking whether the only element is a celebrity or not
	int temp = st.top();
	for (int i = 0; i < n; ++i) {
		if (i != temp and arr[i][temp] == 0)return -1;
	}
	for (int i = 0; i < n; ++i) {
		if (i != temp and arr[temp][i] == 1)return -1;
	}

	return temp;
}

int main() {

	vector<vector<int>> arr{{0, 1}, {1, 0}};
	int n = arr.size();
	cout << Celebrity(arr, n);

	return 0;
}