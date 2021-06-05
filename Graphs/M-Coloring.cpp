// M coloring: T.C: O(m^n)
// Approach: Traverse each node and assign colors starting from 0 to m
// ********************************************************************************
#include <bits/stdc++.h>
using namespace std;

bool isSafe(bool g[][101], int n, int col[], int src, int color) {
    for (int i = 0; i < n; i++) {
        if (i != src and g[src][i] == 1 and col[i] == color)return false;
    }
    return true;
}

bool graphColoring(bool g[][101], int n, int m, int col[], int src) {
    if (src == n) {
        return true;
    }

    for (int i = 0; i < m; i++) {
        if (isSafe(g, n, col, src, i)) {
            col[src] = i;
            if (graphColoring(g, n, m, col, src + 1))return true;
            col[src] = -1;
        }
    }
    return false;
}

int main() {
    // n vertices m color e edges
    int n, m, e;
    cin >> n >> m >> e;
    bool graph[101][101];
    for (int i = 0; i < n; i++) {
        memset(graph[i], 0, sizeof(graph[i]));
    }
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1][b - 1] = 1;
        graph[b - 1][a - 1] = 1;
    }

    // color array
    int col[n];
    memset(col, -1, sizeof col);

    cout << graphColoring(graph, n, m, col, 0) << endl;

    return 0;
}