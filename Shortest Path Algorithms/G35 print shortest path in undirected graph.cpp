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
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n+1); // Adjacency list for the graph
        for(auto edge : edges){
            int u = edge[0], v = edge[1], edgeWeight = edge[2];
            adj[u].push_back({v, edgeWeight}); // Add edge u-v with weight
            adj[v].push_back({u, edgeWeight}); // Add edge v-u with weight (undirected graph)
        }
        
        set<pair<int, int>> st; // Set to maintain nodes with their distances
        st.insert({0, 1}); // Insert the starting node with distance 0
        
        vector<int> dist(n+1, INT_MAX); // Distance array, initialized to infinity
        dist[1] = 0; // Distance to the starting node is 0
        
        vector<int> parent(n+1, -1); // Parent array for path reconstruction
        parent[1] = 1; // Parent of the starting node is itself
        
        while(!st.empty()){
            auto it = *(st.begin()); // Extract the node with minimum distance
            int node = it.second;
            int d = it.first;
            st.erase(it); // Remove the node from the set
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgeWeight = it.second;
                
                // If a shorter path to adjNode is found
                if(dist[adjNode] > d + edgeWeight){
                    if(dist[adjNode] != INT_MAX) st.erase({dist[adjNode], adjNode});
                    
                    parent[adjNode] = node; // Update the parent
                    dist[adjNode] = d + edgeWeight; // Update the distance
                    st.insert({d + edgeWeight, adjNode}); // Insert the updated distance and node
                }
            }
        }
        // If there's no path to the last node
        if(dist[n] == INT_MAX) return {-1};
        
        vector<int> ans; // To store the shortest path
        int node = n;
        while(parent[node] != node){
            ans.push_back(node); // Add the node to the path
            node = parent[node]; // Move to the parent node
        }
        ans.push_back(1); // Add the starting node to the path
        ans.push_back(dist[n]); // Add the distance to the last node
        
        reverse(ans.begin(), ans.end()); // Reverse to get the correct order
        
        return ans;
    }
};

/**
 * Time Complexity (TC):
 * - The overall time complexity of this implementation is O((N + M) * logN) where N is the number of nodes and M is the number of edges.
 * - Constructing the adjacency list takes O(M) time.
 * - Each operation in the set (insert and erase) takes O(logN) time.
 * - The while loop runs N times, and within each loop, the for loop runs M times.
 * - Therefore, the overall time complexity is O((N + M) * logN).

 * Space Complexity (SC):
 * - The space complexity is dominated by the adjacency list, the distance array, the parent array, and the set.
 * - The adjacency list takes O(M) space.
 * - The distance array and parent array each take O(N) space.
 * - The set takes O(N) space.
 * - Therefore, the overall space complexity is O(N + M).
 */
