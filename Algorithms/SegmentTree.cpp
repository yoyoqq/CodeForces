#include <iostream>
#include <bits/stdc++.h>
using namespace std;



class SegmentTree{
    vector<int> tree;
    int n;

public:
    SegmentTree(vector<int>& arr){
        n = arr.size();
        tree.resize(n*4);
        build(0, 0, n-1, arr);
    }

    void build(int node, int start, int end, vector<int>& arr){
        if (start == end){
            tree[node] = arr[start];
        }
        int mid = (start + end) / 2;
        build(2 * node + 1, start, mid, arr);
        build(2 * node + 2, mid + 1, end, arr);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int query(int node, int start, int end, int l, int r){
        // no overlap
        if (r < start || end < l) return 0;
        // complete overlap
        if (l <= start && end <= r) return tree[node];

        int mid = (start + end) / 2;
        int left = query(2 * node + 1, start, mid, l, r);
        int right = query(2 * node + 2, mid + 1, end, l, r);

        return left + right;
    }

    void update(int node, int start, int end, int idx, int val){
        if (start == end){
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2 * node + 1, start, mid, idx, val);
        else update(2 * node + 2, mid + 1, end, idx, val);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
};


int main(){
    return 0; 
}  
