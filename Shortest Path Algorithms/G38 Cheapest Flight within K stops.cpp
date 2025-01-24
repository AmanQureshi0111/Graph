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
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        queue<pair<int,pair<int,int>>> q; //stop,node,cost
        q.push({0,{src,0}});
        
        vector<int> prices(n,INT_MAX);
        prices[src]=0;
        
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            
            int stops=curr.first;
            int node=curr.second.first;
            int cost=curr.second.second;
            
            if(stops>K) continue;
            
            for(auto it:adj[node]){
                int adjNode=it.first;
                int wt=it.second;
                if(prices[adjNode]>cost+wt){
                    prices[adjNode]=cost+wt;
                    q.push({stops+1,{adjNode,prices[adjNode]}});
                }
            }
        }
        
        return prices[dst]==INT_MAX? -1 : prices[dst];
    }
};