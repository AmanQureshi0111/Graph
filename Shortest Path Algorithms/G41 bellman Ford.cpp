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
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        
        vector<int> dist(V, 1e8); // Distance array to store minimum distances from src
        dist[src] = 0; // Distance to source is 0
        
        for(int i = 0; i < V - 1; i++) { // Iterate V-1 times
            for(auto it : edges) {
                int u = it[0], v = it[1], edgeWeight = it[2];
                if(dist[u] != 1e8 && dist[u] + edgeWeight < dist[v]) {
                    dist[v] = dist[u] + edgeWeight; // Relax the edge
                }
            }
        }
        
        // Check for negative-weight cycle
        for(auto it : edges) {
            int u = it[0], v = it[1], edgeWeight = it[2];
            if(dist[u] != 1e8 && dist[u] + edgeWeight < dist[v]) {
                return {-1}; // Return -1 if a negative cycle is detected
            }
        }
        
        return dist; // Return the array of distances
    }
};

/**
 * Time Complexity (TC):
 * - The overall time complexity of this implementation is O(V * E) where V is the number of vertices and E is the number of edges.
 * - The algorithm iterates through all edges V-1 times.
 * - Therefore, the overall time complexity is O(V * E).

 * Space Complexity (SC):
 * - The space complexity is dominated by the distance array.
 * - The distance array takes O(V) space.
 * - Therefore, the overall space complexity is O(V).
 */
