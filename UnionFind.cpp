#include<bits/stdc++.h>
#define fastIO   ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int      long long 
#define all(v)   (v).begin(), (v).end()
using namespace std;

class UnionFind{
	public:
	//parent stores immediate parent, and rank stores the height of the tree
	vector<int> parent, rank;
	UnionFind(int n) {
		rank.assign(n,0); //initially all subtrees have the height of zero
		parent.assign(n,0);
		for(int i=0; i<n; i++) parent[i] = i;
	}
	int findSet(int i) {
		//notice the path compression
		return (parent[i] == i) ? i : (parent[i] = findSet(parent[i]));
	}
	void unionSet(int i, int j) {
		//notice the union by rank
		i = findSet(i), j = findSet(j);
		if(i == j) return;
		if(rank[i] > rank[j]) parent[j] = i;
		else {
			parent[i] = j;
			if(rank[i] == rank[j])  rank[j]++;
		}
	}
	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
};

int32_t main()
{
	fastIO;
}