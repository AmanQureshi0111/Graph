/*  kahn's algo is only applicable on DAG(Directed Acyclic Graph). 
    if the graph contains cycle it will not be able to store all node in topological sorting array
    therefore  it contains cycle 
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
using namespace std;
#include<queue>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  vector<vector<int>> adj(n+1);
  for(auto edge:edges){
    int u=edge.first,v=edge.second;
    adj[u].push_back(v);
  }
  vector<int> indegree(n+1,0);
  for(int i=1;i<=n;i++){
    for(auto it:adj[i]) indegree[it]++;
  }
  queue<int> q;
  for(int i=1;i<=n;i++){
    if(indegree[i]==0) q.push(i);
  }

  int cnt=0;
  while(!q.empty()){
    int node=q.front();
    q.pop();
    for(auto it:adj[node]){
      indegree[it]--;
      if(indegree[it]==0) q.push(it);
    }
    cnt++; // count element stored in topological sort
  }
  return cnt!=n;//n -> no of nodes
}