#include<bits/stdc++.h>
using namespace std;
int n=1000;
int parent[100000];
int rnk[100000]; //rank
void makeset()
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        rnk[i]=0;
    }
}
int findparent(int node)
{
 if(node==parent[node])
 return node;
 return parent[node]=findparent(parent[node]);
}
void union_fun(int u,int v)
{
u=findparent(u);
v=findparent(v);
if(rnk[u]<rnk[v])
parent[u]=v;
else if(rnk[v]<rnk[u])
parent[v]=u;
else{
    parent[v]=u;
    rnk[u]++;
}
}
void main()
{
    makeset();
    int m;
    cin>>m;
    while (m--)
    {
        int u,v;
        union_fun (u,v);
        
    }
    return;
}