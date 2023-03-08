#include<bits/stdc++.h>
#define fastIO   ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int      long long 
#define all(v)   (v).begin(), (v).end()
using namespace std;

//Range sum and point update

class SegmentTree{
	public:
	vector<int> st;
	vector<int> a;
	int n;

	SegmentTree(vector<int> &A)
	{
		a = A, n = A.size();
		st.assign(4*n, 0);
		build(1, 0, n-1);
	}

	int build(int index, int l, int r)
	{
		if(l == r) return st[index] = a[l];
		int mid = l+(r-l)/2;
		return st[index] = build(2*index, l, mid) + build(2*index+1, mid+1, r);
	}

	int updateU(int index, int l, int r, int pos, int val) 
	{
		if(l==r)
		{
			a[pos] = val;
			return st[index] = val;
		}
		int mid = l + (r-l)/2;
		if(pos <= mid) updateU(2*index, l, mid, pos, val);
		else updateU(2*index+1, mid+1, r, pos, val);
		return st[index] = st[2*index] + st[2*index+1];
	}

	int sumU(int index, int l, int r, int cl, int cr)
	{
		if(cl > cr) return 0;
		if(cl == l && cr == r) return st[index];
		int mid = l+(r-l)/2;
		return sumU(2*index, l, mid, cl, min(cr, mid)) + 
			   sumU(2*index+1, mid+1, r, max(cl, mid+1), cr);	
	}

	//user utility methods
	int update(int cl, int cr) { return updateU(1, 0, n-1, cl, cr); }
	int sum(int cl, int cr) { return sumU(1, 0, n-1, cl, cr); }
};

void solve()
{	
	vector<int> a{1,2,3,4,5,6,7};
	SegmentTree st(a);

	st.update(6, 0);
	cout<<st.sum(4, 6)<<"\n";
}

int32_t main()
{
	fastIO;
	int tc=1;
	//cin>>tc;
	for(int i=1;i<=tc;i++)
		solve();
}	

//Segment tree using array, this does not consider node as objects