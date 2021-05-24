#include <iostream>
#include <vector>
using namespace std;

// Min Heap
class Heap {
	vector<int> pq;
public:
	int getsize() {
		return pq.size();
	}
	bool isEmpty() {
		return pq.size() == 0;
	}
	int getTop() {
		if (pq.empty())return -1;
		return pq[0];
	}
	void insert(int val) {
		pq.push_back(val);
		int childIndex = pq.size() - 1;

		// Up heapify
		while (childIndex > 0) {
			int parentIndex = (childIndex - 1) / 2;

			// swap parent and child
			if (pq[parentIndex] > pq[childIndex])swap(pq[parentIndex], pq[childIndex]);
			else break;
			childIndex = parentIndex;
		}

		return;
	}

	void remove() {
		if (pq.empty())return;

		// swap with last element
		pq[0]  = pq[pq.size() - 1];
		pq.pop_back();

		int parentIndex = 0;
		int leftChild = 2 * parentIndex + 1, rightChild = 2 * parentIndex + 2;

		// down heapify
		while (leftChild < pq.size()) {
			int minIndex = parentIndex;
			if (pq[leftChild] < pq[minIndex])minIndex = leftChild;
			if (pq[rightChild] < pq[minIndex])minIndex = rightChild;

			if (minIndex == parentIndex)break;

			swap(pq[parentIndex], pq[minIndex]);
			parentIndex = minIndex;
			leftChild = 2 * parentIndex + 1, rightChild = 2 * parentIndex + 2;
		}

		return;
	}
};


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Heap pq;

	pq.insert(10);
	pq.insert(2);
	pq.insert(5);
	pq.insert(15);
	pq.insert(144);
	pq.insert(10);
	pq.insert(1);


	cout << pq.getTop() << " " << pq.getsize() << endl;;

	while (!pq.isEmpty()) {
		cout << pq.getTop() << " ";
		pq.remove();
	}


	return 0;
}