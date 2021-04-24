//Tarjan's Algorithm
#include<bits/stdc++.h>
using namespace std;

vector< vector<int> >  adj, ans;
vector<bool> visited;
vector<int> discovery; //the first time we discover this node
vector<int> low;
//the earliest possible time at which the node discovered is accessible from here
//in the process of finding the low value for child, we will have to exclude the parent-child edge
int timer = 0;

void dfs(int src, int par) {
    visited[src] = true;
    discovery[src] = low[src] = timer++;
    
    for(int &node : adj[src]) {
        if(node == par) continue; //ignore the edge to the parent
        if(visited[node]) { //src to node is a back edge, can't be a bridge
            low[src] = min(low[node], low[src]);
        } else {
            dfs(node, src);
            low[src] = min(low[src], low[node]); //my child could have a got a better low
            if(low[node] > discovery[src]) { //this is a bridge
                ans.push_back({src, node});
            }
        }
    }
}

int main()
{
    int n, e;
    cin>>n>>e;
    adj.assign(n, vector<int>());
    visited.assign(n, false);
    discovery.assign(n, -1);
    low.assign(n, -1);
    
    for(int i=1; i<=e; i++) {
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    for(int i=0; i<n; i++)
        if(!visited[i])
            dfs(i, -1);
        
    for(vector<int> v : ans)
        cout<<v[0]<<" "<<v[1]<<"\n";
}