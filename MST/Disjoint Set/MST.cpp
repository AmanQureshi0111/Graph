/*Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers. Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge.

Input:
3 3
0 1 5
1 2 3
0 2 1

Output: 4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.
*/

//A minimum spanning tree (MST) is defined as a spanning tree that has the minimum weight among all the possible spanning trees

#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<set>
using namespace std;

//Krushkal's Algo
class DisJointSet{
  vector<int> parent,size;
  public:
    DisJointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++) parent[i]=i;
    }
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y){
        int xParent=find(x);
        int yParent=find(y);
        if(xParent==yParent) return;
        if(size[xParent]>size[yParent]){
            parent[yParent]=xParent;
            size[xParent]+=size[yParent];
        }else{
            parent[xParent]=yParent;
            size[yParent]+=size[xParent];
        }
    }
};
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // kruskal algo
        int mst=0;
        vector<vector<int>> edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){ 
                edges.push_back({it[1],i,it[0]}); //weight,node,adjNode
            } 
        }
        sort(edges.begin(),edges.end());
        DisJointSet ds(V);
        for(auto it:edges){
            int wt=it[0],u=it[1],v=it[2];
            if(ds.find(u)!=ds.find(v)){
                mst+=wt;
                ds.Union(u,v);
            }
        }
        return mst;
    }
};

//Prim's Algo
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        int sum=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});//wt,node
        vector<int> vis(V,0);
        while(!pq.empty()){
            int node=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
            
            if(vis[node]) continue;
            vis[node]=1;
            sum+=wt;
            for(auto it:adj[node]){
                if(!vis[it[0]]){
                    pq.push({it[1],it[0]});
                }
            }
        }
        return sum;
    }
};