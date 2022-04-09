#include <bits/stdc++.h>
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define int long long
#define all(v) (v).begin(), (v).end()
using namespace std;

const int mod = 1e9 + 7;
int add(int a, int b) { return (a % mod + b % mod) % mod; }
int mult(int a, int b) { return (a % mod * b % mod) % mod; }
int sub(int a, int b) { return (a % mod - b % mod + mod) % mod; }

//update(pos,val) -> updates value at index pos to val
//min(l,r) -> returns the index in range [l..r] which has the least value
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
		if(l == r) return st[index] = l;
		int mid = l+(r-l)/2;
        int left = build(2*index, l, mid);
        int right =  build(2*index+1, mid+1, r);
        return st[index] = (a[left] < a[right]) ? left : right;
    }

	int updateU(int index, int l, int r, int pos, int val) 
	{
		if(l == r) {
			a[pos] = val;
			return st[index] = pos;
		}
		int mid = l + (r-l)/2;
		if(pos <= mid) updateU(2*index, l, mid, pos, val);
		else updateU(2*index+1, mid+1, r, pos, val);
        int left = st[2*index];
        int right = st[2*index+1];
		return st[index] = (a[left] < a[right]) ? left : right;
	}

	int minU(int index, int l, int r, int cl, int cr)
	{   
		if(cr < l || r < cl) return 1e9;
		if(cl == l && r == cr) return st[index];
		int mid = l+(r-l)/2;
        int left = minU(2*index, l, mid, cl, min(mid, cr));
        int right = minU(2*index+1, mid+1, r, max(mid+1, cl), cr);
        if(left == 1e9) return right;
        if(right == 1e9) return left;
        return (a[left] < a[right]) ? left : right;
    }

	//user utility methods
	int update(int cl, int cr) { return updateU(1, 0, n-1, cl, cr); }
	int minnn(int cl, int cr) { return minU(1, 0, n-1, cl, cr); }
};

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int &x : a) cin>>x;
    SegmentTree *st = new SegmentTree(a);

    //TEST
// 1
// 5
// 6 1 3 2 1
// 4
// 1 2
// 2 3
// 2 4
// 2 5

    cout<<st->update(0, 899)<<"\n";
    for(int num : st->a)
        cout<<num<<" ";
    cout<<"\n";
    cout<<st->update(2, -100)<<"\n";
    for(int num : st->a)
        cout<<num<<" ";
    cout<<"\n";
    cout<<st->minnn(0, 4)<<"\n";
    cout<<st->minnn(1, 1)<<"\n";
    cout<<st->minnn(2, 4)<<"\n";
    cout<<st->minnn(3, 4)<<"\n";
    cout<<st->minnn(4, 4)<<"\n";
}

int32_t main()
{
    fastIO;
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        //cout<<"Case #"<<i<<": ";
        solve();
    }
}