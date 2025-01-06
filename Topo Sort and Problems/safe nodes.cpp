/*  A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

    Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order. 
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
    bool dfs(int node,vector<int> &vis,vector<vector<int>> &graph){
        vis[node]=2;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(!dfs(it,vis,graph)) return false;
            }else if(vis[it]==2) return false;
        }
        vis[node]=1;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,graph);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(vis[i]==1) ans.push_back(i);
        }
        return ans;
    }
};