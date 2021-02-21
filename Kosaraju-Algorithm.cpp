#include<bits/stdc++.h>
#define fastIO   ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int      long long 
#define all(v)   (v).begin(), (v).end()
using namespace std;

vector< vector<int> > adj, revAdj;
vector< bool > visited;
vector< int > component;
stack<int> st;
int n, e;

void dfs(int src)
{
	visited[src] = true;
	for(int node : adj[src])
		if(!visited[node])
			dfs(node);
	st.push(src);
}

void dfs1(int src, int id)
{
	visited[src] = true;
	component[src] = id;
	for(int node : revAdj[src])
		if(!visited[node])
			dfs1(node, id);
}

void solve()
{	
	cin>>n>>e;
	adj.assign(n, vector<int>()); //nodes indexing as 0
	revAdj.assign(n, vector<int>());
	visited.assign(n, false);
	component.assign(n, -1);

	for(int i=1; i<=e; i++)
	{
		int x, y;
		cin>>x>>y;
		//there is an edge from x -> y
		adj[x].push_back(y);
		revAdj[y].push_back(x);
	}

	for(int i=0; i<n; i++)
		if(!visited[i])
			dfs(i);

	fill(all(visited), false);
	while(!st.empty())
	{
		int t = st.top();
		st.pop();
		if(visited[t]) continue;
		dfs1(t, t);
	}

	for(int i=0; i<n; i++)
		cout<<component[i]<<" ";
}

int32_t main()
{
	fastIO;
	int tc=1;
	//cin>>tc;
	for(int i=1;i<=tc;i++)
		solve();
}	

//Kosaraju Algorithm - finding all strongly connected components(SCC)
//SCC - if we can reach from every vertex to every other vertex in a component
//1)DFS and store in stack
//2)Reverse the adjacecy list
//3)DFS and store the components