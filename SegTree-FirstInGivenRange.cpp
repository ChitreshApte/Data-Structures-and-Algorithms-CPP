#include <bits/stdc++.h>
using namespace std;

//Given a range [tl,tr] and a val k, find first index idx in [tl, tr] such that 
//value at that index is greater than k, if not return -1, and update queries
class SegmentTree{
    public:
    vector<int> st;
    vector<int> a;
    int n;
    
    SegmentTree(vector<int> &A) {
        a = A;
        n = A.size();
        st.assign(4*n, 0);
        build(1, 0, n-1);
    }
    
    void build(int index, int l, int r) {
        if(l == r) {
            st[index] = a[l];
            return;
        }
        int mid = l+(r-l)/2;
        build(2*index, l, mid);
        build(2*index+1, mid+1, r);
        st[index] = max(st[2*index], st[2*index+1]);
    }
    
    //[l,r] denotes the current searching range
    //index = 1, l = 0, r = n-1 while call
    void update(int idx, int val, int index, int l, int r) {
        if(idx < l || r < idx) return;
        if(l == r) {
            st[index] = val;
            return;
        } 
        int mid = l+(r-l)/2;
        update(idx, val, 2*index, l, mid);
        update(idx, val, 2*index+1, mid+1, r);
        st[index] = max(st[2*index], st[2*index+1]);
    }
    
    //[l,r] denotes the current searching range
    //index = 1, l = 0, r = n-1 while call
    int query(int reqL, int reqR, int index, int l, int r) {
        if(reqR < l || r < reqL) return INT_MIN;
        if(l == r) return st[index];
        int mid = l+(r-l)/2;
        int left = query(reqL, min(mid, reqR), 2*index, l, mid);
        int right = query(max(mid+1, reqL), reqR, 2*index+1, mid+1, r);
        return max(left, right);
    }

    ////[l,r] denotes the current searching range
    //index = 1, l = 0, r = n-1 while call
    //returns first index with value greater than k in the range tl to tr
    int helper(int k, int tl, int tr, int index, int l, int r) {
        if(tr < l || r < tl) return -1;
        if(tl <= l && r <= tr) { //this full range [l,r] is part of [tl, tr]
            if(st[index] <= k) return -1;
            while(l != r) {
                int mid = l + (r-l)/2;
                if(st[2*index] > k) r = mid, index = 2*index;
                else l = mid+1, index = 2*index+1;
            }
            return l;
        }

        int mid = l + (r-l) / 2;
        int inLeft = helper(k, tl, tr, 2*index, l, mid);
        if(inLeft != -1) return inLeft;
        return helper(k, tl, tr, 2*index+1, mid+1, r);
    }
};

int main() {
    
    int n;
    cin>>n;
    vector<int> a(n);
    for(int &x : a) cin>>x;
    int k, tl, tr;
    cin>>k>>tl>>tr;

    SegmentTree seg(a);
    
    int idx = seg.helper(k, tl, tr, 1, 0, n-1);
    cout<<idx<<"\n";
}