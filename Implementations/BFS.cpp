#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
using namespace std;
vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        int n=adj.size();
        vector<int>  vis(n,0);
        vis[0]=1;
        queue<int> q;
        q.push(0);
        vector<int> BFS;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            BFS.push_back(node);
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return BFS;
    }
