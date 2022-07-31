/*Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, 
vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.*/
//cyclic defies linear order therefore topo sort doesn't work
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    queue<int>q;
	    vector<int>indegree(V,0);     //indegree is the no of incoming vertices to the node
        // for our graph_topo_sort.png 0 has indegree of 2 (4 & 5)
	    for(int i=0;i<V;i++)
	    {
	        
            for(auto it:adj[i])
	        indegree[it]++;        
	    }
        for(int i=0;i<V;i++)
	    {
            if(indegree[i]==0)
            q.push(i);
        }
	    vector<int>topo;
	    while(!q.empty())
	    {
	       int node=q.front();
           q.pop();
           topo.push_back(node);
           for (auto it:adj[node])
           {
            indegree[it]--;
            if(indegree[it]==0)
            q.push(it);
           }
	    }
	    return topo;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends