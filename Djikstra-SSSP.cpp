#include <bits/stdc++.h>
using namespace std;

int n, e;
vector< vector< pair<int,int> > >  adj;
vector< int > dist, par;

void dijkstra(int s) {
    dist.assign(n+1, 1e9);
    par.assign(n+1, -1);
    
    priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push({0,s});
    
    dist[s] = 0;
    
    while(!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        //this node is just old one no need to consider it
        if(d != dist[node]) continue;
        
        for(pair<int,int> x : adj[node]) {
            int v = x.first;
            int weight = x.second;
            if(d+weight < dist[v]) {
                dist[v] = d+weight;
                par[v] = node;
                pq.push({dist[v], v});
            }
        }
    }
    
    for(int i=1; i<=n; i++)
        cout<<dist[i]<<" ";
    cout<<"\n";
}

int main() {
    cin>>n>>e;
    adj.assign(n+1, vector<pair<int,int>>());
    
    for(int i=1; i<=e; i++) {
        int x, y, w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    int s;
    cin>>s;
    dijkstra(s);
}