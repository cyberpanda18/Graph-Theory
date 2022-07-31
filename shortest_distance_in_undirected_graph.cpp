//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// weight of each node is 1

class Solution {
  public:
   void bfs(int V, vector<int>adj[],int src)
   {
     int dist[V]; //distance of src to each node at i'th position
     for(int i=0;i<V;i++) dist[i]=INT16_MAX;
     queue<int>q;
     dist[src]=0;
     q.push(src);
     while (!q.empty())
     {
        int node=q.front();
        q.pop();
        for (auto it:adj[node])
        {
            if(dist[node]+1<dist[it])
            {
                dist[it]=dist[node]+1;
                q.push(it);
            }
        }
        
     }
     for(int i=0;i<V;i++) cout<<dist[i]<<" ";
     
   }
        
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
       int src; cin>>src;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
    
        Solution obj;
        obj.bfs(V, adj,src);
    }

    return 0;
}

// } Driver Code Ends
// sample inp : 1 4 7 0 0 1 0 2 1 2 1 3 2 0 2 3 3 3
//output 0 1 1 2
//refer graph.png