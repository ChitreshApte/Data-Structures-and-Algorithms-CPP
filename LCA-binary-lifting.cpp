//For aggrigate values along with the LCA, check ENOC1
//The nodes are numbered from 1
#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5, LOGN=25;
vector< vector<int> > adj;
int p[N][LOGN]; //ancestors with powers of 2
int h[N]; //distance from the root node
int n;

void dfs(int src, int par) {
    
    p[src][0] = par; //setting immediate parent
    h[src] = h[par]+1; //updating the distance
    
    for(int i=1; i<LOGN; i++) 
        p[src][i] = p[p[src][i-1]][i-1];
    
    for(int node : adj[src])
        if(node != par)
            dfs(node, src);
}

int lca(int x, int y) {
    if(h[x] < h[y]) swap(x, y);
    //x is now more distant from the root
    int dif = h[x] - h[y];
    
    for(int i=0; i<LOGN; i++) {
        if(dif&(1<<i)) {
            x = p[x][i];
        }
    }
    
    //now both are at the same height
    
    if(x == y) return x;
    
    for(int i=LOGN-1; i>=0; i--) {
        if(p[x][i] != p[y][i]) {
            x = p[x][i];
            y = p[y][i];
        }
    }
    
    return p[x][0];
}

int main() {
    cin>>n;
    
    adj.assign(n+1, vector<int>());
    for(int i=1; i<n; i++) {
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    //self loop at the top of the tree
    for(int i=0; i<LOGN; i++)
        p[0][i] = 0;
        
    //the nodes are 1-indexed
    dfs(1,0);
    
    //LCA queries
    int q;
    cin>>q;
    while(q--)
    {
        int x, y;
        cin>>x>>y;
        cout<<lca(x,y)<<"\n";
    }    
}