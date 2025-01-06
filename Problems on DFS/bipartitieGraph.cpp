/*  Given an adjacency list of a graph adj. Check whether the graph is bipartite or not.

    A bipartite graph can be colored with two colors such that no two adjacent vertices share the same color. This means we can divide the graph’s vertices into two distinct sets where:
*/
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
    bool dfs(int node,vector<int> &color,vector<vector<int>> &adj){
        for(auto it:adj[node]){
            if(color[it]==-1){
                color[it]=!color[node];
                if(!dfs(it,color,adj)) return false;
            }else if(color[node]==color[it]) return false;
        }
        return true;
    }
  public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> color(n,-1);
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                if(!dfs(i,color,adj)) return false;
            }
        }
        return true;
    }
};

// BFS
class Solution {
private:
    bool bfs(int start,vector<int> &color,vector<vector<int>> &graph){
        color[start]=0;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int it:graph[node]){
                if(color[it]==-1){
                    q.push(it);
                    color[it]=!color[node];
                }else if(color[node]==color[it]) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!bfs(i,color,graph)) return false;
            }
        }
        return true;
    }
};