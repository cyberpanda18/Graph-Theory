#include <bits/stdc++.h> 
#define INF INT_MAX 
using namespace std; 

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
    int src=0;
    //Dijkstra's algorithm
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;//min heap
	vector<int>dist(n+1,INT_MAX);
    dist[src]=0;
    pq.push({0,src});  //(dist,from)
    while (!pq.empty())
    {
        int dis=pq.top().first;
        int prev=pq.top().second;
        pq.pop();
        vector<pair<int,int>>::iterator it;
        for(it=adj[prev].begin();it!=adj[prev].end();it++)
        {
            int next=it->first;
            int nextDist=it->second;
            if(dist[next]>dist[prev]+nextDist)
            {
                dist[next]=dist[prev]+nextDist;
                pq.push({dist[next],next});
            }
        }
    }
    cout<<"The distance from source "<<src<<", are: \n";
    for(int i=1;i<=n;i++)
    cout<<dist[i]<<" ";
    cout<<endl;
    
    return 0; 
} 
//inp : 6 9 0 1 5 0 2 3 1 3 6 1 2 2 2 4 4 2 5 2 2 3 7 3 4 -1 4 5 -2      
//op : 0 5 3 10 7 5  