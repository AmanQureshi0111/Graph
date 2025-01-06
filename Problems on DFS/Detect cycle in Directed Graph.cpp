// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
using namespace std;
class Solution {
  private:
    // 1->visited
    // 2->pathVisited
    bool dfs(int node,vector<int> &vis,vector<vector<int>> &adj){
        vis[node]=2;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,adj)) return true;
            }else if(vis[it]==2) return true;
        }
        vis[node]=1;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,adj)) return true;
            }
        }
        return false;
    }
};