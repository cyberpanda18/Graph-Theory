/* A Bipartite Graph is a graph whose vertices can be divided into two independent sets, 
U and V such that every edge (u, v) either connects a vertex from U to V or a vertex from V to U.
 In other words, for every edge (u, v), either u belongs to U and v to V, or u belongs to V and v to U. 
 We can also say that there is no edge that connects vertices of same set.
A bipartite graph is possible if the graph coloring is possible using
 two colors such that vertices in a set are colored with the same color. 
Note that it is possible to color a cycle graph with even cycle using two colors. 
It is not possible to color a cycle graph with odd cycle using two colors. */
//color all nodes of a graph using just 2 colors and no two adjacent nodes should have same color
//only graph which is no bipartite is the one with an odd number of nodes in a cycle

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>color(V,-1);
	    //colors used are 0(B) or 1(G)
	    queue<pair<int,int>>q; //{vertex,color}
	    //loop in case graph is not connected
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
	            q.push({i,0});
	            color[i]=0;
	            while(!q.empty())
	            {
	                pair<int,int>p=q.front();
	                q.pop();
	                int v=p.first; //vertex
	                int c=p.second; //color
	                for(int j:adj[v])
	                {
	                    if(color[j]==c) return false;
	                    if(color[j]==-1)
	                    {
	                        color[j]=(c==1)?0:1;
	                        q.push({j,color[j]});
	                    }
	                }
	            }
	        }
	    }
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends