    #include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
using namespace std;
    //DFS
        bool isCycle(int node,int parentNode,vector<vector<int>> &adj,vector<int> &visited){
        visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                if(isCycle(it,node,adj,visited)) return true;;
            }else if(parentNode != it){
                return true;
            }
        }
        return false;
    }
    string cycleDetection (vector<vector<int>>& edges, int n, int m)
    {
        bool ans=false;
        vector<vector<int>> adj(n+1);
        for(auto edge:edges){
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n+1,0);
        for(int i=1;i<n+1;i++){
            if(!visited[i]){
                if(isCycle(i,-1,adj,visited)) {
                    ans=true;
                    break;
                }
            }
        }
        return ans ? "Yes" :"No";
    }

   //BFS
    bool isCycle(int node,int parentNode,vector<vector<int>> &adj,vector<int> &visited){
        visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                if(isCycle(it,node,adj,visited)) return true;;
            }else if(parentNode != it){
                return true;
            }
        }
        return false;
    }
    string cycleDetection (vector<vector<int>>& edges, int n, int m)
    {
        bool ans=false;
        vector<vector<int>> adj(n+1);
        for(auto edge:edges){
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n+1,0);
        for(int i=1;i<n+1;i++){
            if(!visited[i]){
                if(isCycle(i,-1,adj,visited)) {
                    ans=true;
                    break;
                }
            }
        }
        return ans ? "Yes" :"No";
    }
