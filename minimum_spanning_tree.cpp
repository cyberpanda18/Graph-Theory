// a tree that can be drawn from a graph and contain n nodes and only n-1 edges is called spanning tree
// lose any cycle but make sure you can reach all n-1 nodes from any node
// The tree whose sum of edges' weights is minumum of all spanning trees is called MST
// Prim's Algorithm 

#include <bits/stdc++.h> 
#define INF INT_MAX 
using namespace std; 

void Prims(int n,vector<pair<int,int>> adj[])
{
    int parent[n];  //contains result
    int key[n];
    bool mst[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        key[i]=INF;
        parent[i]=-1;
        mst[i]=false;
    }
    key[0]=0;
    parent[0]=-1;
    for(int i=0;i<n-1;i++)
    {
        int mini=INT16_MAX,u;
        for(int v=0;v<n;v++)
        {
            if(mst[v]==false && key[v]<mini)
            mini=key[v],u=v;
        }
        mst[u]=true;
        for(auto it: adj[u])
        {
            int v=it.first;
            int wt=it.second;
            if(mst[v]==false && wt<key[v])
            parent[v]=u,key[v]=wt;
        }
    }
    for(int i=1;i<n;i++)
     cout<<parent[i]<<" -- "<<i<<endl;
   //  cout<<sum<<endl;
     return;
}
int main() 
{ 
	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> adj[n+1]; 
    int u, v, wt;
	for(int i = 0;i<m;i++) {
	    
	    cin >> u >> v >> wt; 
	    adj[u].push_back({v, wt}); 
	}
    Prims(n,adj);
}