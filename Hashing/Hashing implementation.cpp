// Hash Table Implementation -> Separate Chaining
// ---------------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;
int const prime = 27;

template <typename T>
class Node {
public:
	string key;
	T value;
	Node<T>* next;

	Node(string key, T value) {
		this->key = key;
		this->value = value;
		next = NULL;
	}

	~Node() {
		// recursively deleting 
		if(next != NULL) delete next;
	}
	
};

template <typename T>
class HashTable {
	Node<T>** table; // pointer to an array of pointers
	int current_sz, table_sz;

	int hash_fn(string key) {
		int idx = 0, p = 1;

		for(int i = 0; i < key.length(); ++i) {
			idx = (idx + (key[i]*p)%table_sz)%table_sz;
			p = (p*prime)%table_sz;
		}

		return idx;
	}

	// rehashing
	void rehash() {
		Node<T>** oldTable = table; // oldTable is a pointer pointing to table
		int oldTableSz = table_sz;

		table_sz = 2*table_sz; // or can find the next prime number
		current_sz = 0;
		table = new Node<T> *[table_sz]; // new table with 2*size

		for(int i = 0; i < table_sz; ++i) {
			table[i] = NULL;
		}

		// insert all entities from old table to new table

		for(int i = 0; i < oldTableSz; ++i) {
			Node<T> *temp = oldTable[i];

			while(temp != NULL) {
				insert(temp->key, temp->value); // insert happens in new table
				temp = temp->next;
			}

			if(oldTable[i] != NULL) delete oldTable[i]; 
		}

		delete []oldTable;
	}

public:

	HashTable(int ts = 7) {
		table_sz = ts;
		table = new Node<T>*[ts];
		current_sz = 0;

		for(int i = 0; i < ts; ++i) {
			table[i] = NULL;
		}
	}

	// insert 
	void insert(string key, T val) {
		int idx = hash_fn(key);

		// create a new node
		Node<T> *node = new Node<T>(key,val);

		// insert the new node at head of linked list with id = idx
		node->next = table[idx];
		table[idx] = node;
		current_sz++;

		float load_factor = current_sz/(1.0*table_sz);

		if(load_factor > 0.7) {
			rehash();
		}

		return;
	}	

	// print the hash table
	void print() {

		for(int i = 0; i < table_sz; ++i) {
			cout << "Bucket " << i << " -> ";
			Node<T>* temp = table[i];

			while(temp !=  NULL) {
				cout << temp->key << " " << temp->value << " ";
				temp = temp->next;
			}
			cout << '\n';
		}
	}

	T* search(string key) {
		int idx = hash_fn(key);
		Node<T>* temp = table[idx];

		while(temp != NULL) {
			if(temp->key == key) {
				return &(temp->value);
			}

			temp = temp->next;
		}

		return NULL;
	}

};

int main() {

	// test

	HashTable<int> h;
	h.insert("abc", 10);
	h.insert("def", 1);
	h.insert("ghi", 111);
	h.insert("xyz", 7);
	h.insert("xyz", 17);

	h.print();
	cout <<'\n';

	auto ptr = h.search("xxyz");

	if(ptr != NULL) cout << *ptr;
	else cout << "Not found";


 	return 0;
}