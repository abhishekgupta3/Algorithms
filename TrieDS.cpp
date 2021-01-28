#include <bits/stdc++.h>
using namespace std;

// TrieNode class
class TrieNode {
public:
	char data;
	TrieNode** children;
	bool isEnd;

	TrieNode(char data) {
		this->data = data;
		children = new TrieNode*[26];
		for (int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isEnd = false;
	}
};

// Trie Class
class Trie {
	TrieNode* root;

	// insert util function
	void insertUtil(string input, TrieNode* root) {
		// Base case
		if (input.length() == 0) {
			root->isEnd = true;
			return;
		}
		TrieNode * child;
		int index = input[0] - 'a';

		if (root->children[index] == NULL) {
			child = new TrieNode(input[0]);
			root->children[index] = child;
		}
		else {
			child = root->children[index];
		}

		insertUtil(input.substr(1), child);
	}

	// search util function
	bool searchUtil(string input, TrieNode* root) {
		// Base case
		if (input.length() == 0) return root->isEnd;

		TrieNode * child;
		int index = input[0] - 'a';

		if (root->children[index] == NULL) return false;
		else child = root->children[index];

		return searchUtil(input.substr(1), child);
	}

	// remove util function
	void removeUtil(string input, TrieNode* root) {
		// Base case
		if (input.length() == 0) {
			root->isEnd = false;
			return;
		}

		TrieNode * child;
		int index = input[0] - 'a';

		if (root->children[index] == NULL) return;
		else child = root->children[index];

		removeUtil(input.substr(1), child);

		// delete the children node if it is last node & its all children are null
		if (child->isEnd) {

			for (int i = 0; i < 26; i++) {
				// if there is any child present don't need to delete
				if (child->children[i] != NULL) return;
			}
			delete child; // all children are NULL
			root->children[index] = NULL; // the parent's array should be marked null
		}

	}

public:

	Trie() {
		root = new TrieNode('\0');
	}

	// Insert
	void insert(string input) {
		insertUtil(input, root);
	}

	// search
	bool search(string input) {
		return searchUtil(input, root);
	}

	// remove
	void remove(string input) {
		removeUtil(input, root);
	}

};

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Trie t;
	t.insert("abc");
	t.insert("abd");
	t.insert("abcd");
	t.insert("back");
	t.insert("bad");

	cout << "bac " << t.search("bac") << endl;
	cout << "abcd " << t.search("abcd") << endl;

	cout << "bcd " << t.search("bcd") << endl;
	t.remove("bcd");
	cout << "bcd " << t.search("bcd") << endl;

	t.remove("abcd");
	cout << "abcd " << t.search("abcd") << endl;
	t.remove("back");
	cout << "bad " << t.search("bad") << endl;
	cout << "back " << t.search("back") << endl;



	return 0;

}