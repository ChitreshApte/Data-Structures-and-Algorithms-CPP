#include<bits/stdc++.h>
using namespace std;

class UnionFind{
	public:
	vector<int> parent, rank;
	UnionFind(int n) {
		rank.assign(n,0);
		parent.assign(n,0);
		for(int i=0; i<n; i++) parent[i] = i;
	}
	int findSet(int i) {
		return (parent[i] == i) ? i : (parent[i] = findSet(parent[i]));
	}
	void unionSet(int i, int j) {
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

int n, e;
vector< vector<int> > edges, result;

int main() {
    
    cin>>n>>e;
    edges.clear();
    result.clear();
    
    for(int i=1; i<=e; i++) {
        int w, x, y;
        cin>>w>>x>>y;
        edges.push_back({w,x,y});
    }
    sort(edges.begin(), edges.end());
    
    UnionFind u(n+1);
    
    int cost = 0;
    for(vector<int> edge : edges) {
        if(!u.isSameSet(edge[1], edge[2])) {
            cost += edge[0];
            u.unionSet(edge[1], edge[2]);
            result.push_back(edge);
        }
    }
    
    cout<<cost<<"\n";
    for(vector<int> edge : result) {
        cout<<edge[1]<<" "<<edge[2]<<"\n";
    }
}