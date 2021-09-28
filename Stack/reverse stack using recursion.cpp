#include <bits/stdc++.h>
using namespace std;

void at_last(stack<int>s , int f) {
	if (s.size() == 0) {
		s.push(f); 
		return;
	}

	int temp = s.top();
	s.pop();
	at_last(s, f);
	s.push(temp);
}

void reverse(stack<int> s) {
	if (s.size() == 0)return;
	int f = s.top(); s.pop();
	reverse(s);
	at_last(s, f);

}

int main() {

	stack<int> s;
	s.push(1); 
	s.push(2); 
	s.push(3); 
	s.push(4);

	reverse(s); // O(N^2)

	while (s.empty() == false) {
		cout << s.top(); s.pop(); 
	}

	return 0;
}