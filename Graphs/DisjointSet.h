#include <iostream>

class DSU {
	int *parent;
	int *rank;
public:

	DSU(int V) {
		parent = new int[V];
		rank = new int[V];
		for (int i = 0; i < V; i++)parent[i] = -1, rank[i] = 1;
	}

	// find (Path Compression)
	int find(int x) {
		if (parent[x] == -1)return x;
		return parent[x] = find(parent[x]);
	}

	// union (Union by Rank)
	void union_set(int x, int y) {
		int s1 = find(x);
		int s2 = find(y);

		if (s1 != s2) {
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
			else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
		return;
	}
};