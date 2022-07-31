#include <bits/stdc++.h>
using namespace std;
vector<int>bfstrav(int V,vector<int>adj[])
{
vector<int>bfs;
vector<int>vis(V+1,0);
for(int i=1;i<=V;i++)  // for non connected graph
{
    if(!vis[i])         //visited[i]=0
    {
      queue<int>q;
      q.push(i);
      vis[i]=1;
      while(!q.empty())
      {
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it: adj[node])
        {
           if(!vis[it])
           {
              q.push(it);
              vis[it]=1;
           }
        }
      }
    }
}
return bfs;
}

// using adjency matrix
int main()
{
    int n,m;
    cin>>n>>m;
    int adj[n+1][n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;

    }
    return 0;

}