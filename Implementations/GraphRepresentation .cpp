#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto edge:edges){
            int u=edge.first,v=edge.second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
};
