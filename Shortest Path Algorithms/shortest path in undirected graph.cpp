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
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size(); // Number of nodes
        vector<int> dist(n, INT_MAX); // Distance array
        dist[src] = 0; // Distance to source is 0
        
        // Queue for BFS: stores pairs of (node, distance)
        queue<pair<int, int>> q;
        q.push({src, 0});
        
        while (!q.empty()) {
            auto node = q.front(); // Current node
            q.pop();
            
            for (auto adjNode : adj[node.first]) { // Traverse neighbors
                if (dist[adjNode] > node.second + 1) { // Relax edge
                    q.push({adjNode, node.second + 1});
                    dist[adjNode] = node.second + 1;
                }
            }
        }
        
        // Replace unreachable distances with -1
        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }
        return dist;
    }
};

/*
Time Complexity:
1. BFS traversal: O(V + E), where V is the number of vertices and E is the number of edges.
2. Initialization: O(V).
Overall: O(V + E).

Space Complexity:
1. Distance array: O(V).
2. Queue for BFS: O(V).
3. Adjacency list: O(V + E).
Overall: O(V + E).
*/
