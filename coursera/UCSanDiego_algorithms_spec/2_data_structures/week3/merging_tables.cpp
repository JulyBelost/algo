#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::vector;

struct DisjointSetsElement {
	int size, parent, rank;

	DisjointSetsElement(int size = 0, int parent = -1, int rank = 0):
	    size(size), parent(parent), rank(rank) {}
};

struct DisjointSets {
	int size;
	int max_table_size;
	vector <DisjointSetsElement> elements;

	DisjointSets(int size): size(size), max_table_size(0), elements(size) {
		for (int i = 0; i < size; i++)
			elements[i].parent = i;
	}

	int getParent(int table) {
		if(elements[table].parent != table) {
			elements[table].parent = getParent(elements[table].parent);
		}
		return elements[table].parent;
	}

	void merge(int dest, int src) {
		int realDest = getParent(dest);
		int realSrc = getParent(src);
		if (realDest != realSrc) {
			bool rnk = elements[realSrc].rank > elements[realDest].rank;
			int p = rnk ? realSrc : realDest;
			int ch = rnk ? realDest : realSrc;

			elements[ch].parent = p;
			elements[p].size += elements[ch].size;
			elements[ch].size = 0;
			max_table_size = max(max_table_size, elements[p].size);

			if(elements[realSrc].rank == elements[realDest].rank) {
				++elements[p].rank;
			}
		}
	}
};

int main() {
	int n, m;
	cin >> n >> m;

	DisjointSets tables(n);
	for (auto &table : tables.elements) {
		cin >> table.size;
		tables.max_table_size = max(tables.max_table_size, table.size);
	}

	for (int i = 0; i < m; i++) {
		int destination, source;
		cin >> destination >> source;
                --destination;
                --source;

		tables.merge(destination, source);
	        cout << tables.max_table_size << endl;
	}

	return 0;
}
