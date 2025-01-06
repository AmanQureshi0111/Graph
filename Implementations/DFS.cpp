/*
    Time Complexity: 𝑂(𝑉+𝐸),,where V is the number of vertices and E is the number of edges.
    Space Complexity: O(V) for the visited array, dfs result, and recursion stack.
    Total SC = O(V).
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
using namespace std;
void solve(vector<vector<int>> adj,int node,vector<int> &visited,vector<int> &dfs){
        dfs.push_back(node);
        visited[node]=1;
        for(int it:adj[node]){
            if(!visited[it]){
                solve(adj,it,visited,dfs);
            }
        }
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        vector<int> DFS;
        int n=adj.size();
        vector<int> visited(n,0);
        solve(adj,0,visited,DFS);
        return DFS;
    }