/* TC-O(E*logV)
 */
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

//priority queue
class Solution {
  public:
    
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        //priority_queue
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minH;
        minH.push({0,src});
        int  n=adj.size();
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        
        while(!minH.empty()){
            int distance=minH.top().first;
            int node=minH.top().second;
            minH.pop();
            
            for(auto it:adj[node]){
                int edgeWeight=it.second;
                int adjNode=it.first;
                
                if(dist[adjNode]> dist[node]+edgeWeight){
                    dist[adjNode]=dist[node]+edgeWeight;
                    
                    minH.push({dist[adjNode],adjNode});
                }
            }
        }
        
        return dist;
    }
};
//set
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        set<pair<int,int>> st;
        st.insert({0,src});
        int n=adj.size();
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        
        while(!st.empty()){
            auto it=*(st.begin());
            int node=it.second;
            int d   =it.first;
            st.erase(it);
            
            for(auto it:adj[node]){
                int adjNode=it.first;
                int edgeWeight=it.second;
                
                if(dist[adjNode]==INT_MAX){
                    st.insert({edgeWeight+d,adjNode});
                    dist[adjNode]=edgeWeight+d;
                }else if(dist[adjNode] > edgeWeight+d){
                    st.erase({dist[adjNode],adjNode});
                    st.insert({d+edgeWeight,adjNode});
                    dist[adjNode]=d+edgeWeight;
                }
            }
        }
        
        return dist;
    }
};