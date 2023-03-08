#include <bits/stdc++.h>
using namespace std;

/*
This segments supports
1) Updating the values of an element in the array
2) For a range finding the max element and also its count
*/

class SegmentTree{
    public:
    //first - maximum, second - frequency
    vector< pair<int,int> > st;
    vector<int> a;
    int n;
    
    SegmentTree(vector<int> &A) {
        a = A;
        n = A.size();
        st.assign(4*n, {0,0});
        build(1, 0, n-1);
    }
    
    pair<int,int> combine(pair<int,int> &a, pair<int,int> &b) {
        if(a.first > b.first) return a;
        if(a.first < b.first) return b;
        return {a.first, a.second+b.second};
    }
    
    void build(int index, int l, int r) {
        if(l == r) {
            st[index] = {a[l], 1};
            return;
        }
        int mid = l+(r-l)/2;
        build(2*index, l, mid);
        build(2*index+1, mid+1, r);
        st[index] = combine(st[2*index], st[2*index+1]);
    }
    
    //[l,r] denotes the current searching range
    void update(int idx, int val, int index, int l, int r) {
        if(idx < l || r < idx) return;
        if(l == r) {
            st[index] = {val, 1};
            return;
        } 
        int mid = l+(r-l)/2;
        update(idx, val, 2*index, l, mid);
        update(idx, val, 2*index+1, mid+1, r);
        st[index] = combine(st[2*index], st[2*index+1]);
    }
    
    //[l,r] denotes the current searching range
    pair<int, int> query(int reqL, int reqR, int index, int l, int r) {
        if(reqR < l || r < reqL) return {INT_MIN, 0}; //this will not affect the combine
        if(l == r) return st[index];
        int mid = l+(r-l)/2;
        pair<int,int> left = query(reqL, min(mid, reqR), 2*index, l, mid);
        pair<int,int> right = query(max(mid+1, reqL), reqR, 2*index+1, mid+1, r);
        return combine(left, right);
    }
};

int main() {
    
    int n;
    cin>>n;
    vector<int> a(n);
    for(int &x : a) cin>>x;
    
    SegmentTree seg(a);
    
    pair<int,int> p = seg.query(0, n-1, 1, 0, n-1);
    cout<<p.first<<" "<<p.second<<"\n";
    
}