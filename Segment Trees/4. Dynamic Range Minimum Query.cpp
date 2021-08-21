// Dynamic Range Minimum Query: Point Updates

#include <bits/stdc++.h>
using namespace std;

void buildTree(int* seg, int* arr, int l, int h, int i) {
    if(l == h) {
        seg[i] = arr[l];
        return;
    }
    int mid = (l + h) >> 1;

    buildTree(seg, arr, l, mid, 2 * i);
    buildTree(seg, arr, mid + 1, h, 2 * i + 1);
    seg[i] = min(seg[2 * i], seg[2 * i + 1]);
}

void update(int* seg, int* arr, int l, int h, int a, int b, int i) {
    if(l == h) {
        arr[a] = b;
        seg[i] = b;
        return;
    } 

    int mid = (l + h) >> 1;
    if(a <= mid) {
        update(seg, arr, l, mid, a, b, 2 * i);
    }
    else update(seg, arr, mid + 1, h, a, b, 2 * i + 1);

    seg[i] = min(seg[2 * i], seg[2 * i + 1]);
}

int query(int * seg, int l, int h, int start, int end, int i) {
    if(start > h || end < l) return INT_MAX; // no overlap

    if(l >= start && h <= end) return seg[i];

    int mid = (l + h) >> 1;
    return min(query(seg, l, mid, start, end, 2 * i), query(seg, mid + 1, h, start, end, 2 * i + 1));
}

int main(){

    int n, m; cin >> n >> m;
    int arr[n]; 
    for(int i = 0; i < n; ++i) cin >> arr[i];
    int seg[4 * n] = {};
    
    buildTree(seg, arr, 0, n - 1, 1);

    while(m--) {
        int a, b, type; cin >> type >> a >> b;
        a--;
        if(type == 1) {
            update(seg, arr, 0, n - 1, a, b, 1);
        }
        else b--, cout << query(seg, 0, n - 1, a, b, 1) << '\n';
    }

    return 0;
}