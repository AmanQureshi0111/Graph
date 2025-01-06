/*  Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
*/
// Kahn's Algorithm
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
using namespace std;
class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> inDegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]) inDegree[it]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0) q.push(i);
        }
        
        vector<int> topo;
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int it:adj[curr]){
                if(--inDegree[it]==0 )q.push(it);
            }
            topo.push_back(curr);
        }
        return topo;
    }
};