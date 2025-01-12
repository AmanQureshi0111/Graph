/* 
    There are n cities labeled from 0 to n-1 with m edges connecting them. Given the array edges where edges[i] = [fromi , toi ,weighti]  represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold. You need to find out a city with the smallest number of cities that are reachable through some path and whose distance is at most Threshold Distance. If there are multiple such cities, our answer will be the city with the greatest label.
Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
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
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        const int inf = 1e9; // A large value representing infinity (no direct path)
        
        // Step 1: Initialize distance matrix
        vector<vector<int>> dist(n, vector<int>(n, inf)); // `dist[i][j]` represents the shortest distance from city `i` to city `j`

        // Step 2: Populate initial distances from edges
        for (auto it : edges) {
            dist[it[0]][it[1]] = it[2]; // Set the weight of the edge from `it[0]` to `it[1]`
            dist[it[1]][it[0]] = it[2]; // Since the graph is undirected, set the weight for both directions
        }

        // Step 3: Set self-loop distances to 0
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0; // Distance from a city to itself is always 0
        }

        // Step 4: Apply Floyd-Warshall Algorithm to find all-pairs shortest paths
        for (int via = 0; via < n; via++) { // Intermediate node `via`
            for (int i = 0; i < n; i++) {   // Start node `i`
                for (int j = 0; j < n; j++) { // End node `j`
                    // Update `dist[i][j]` if a shorter path exists via `via`
                    if (dist[i][via] == inf || dist[via][j] == inf) continue; // Skip if any path is "infinity"
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }

        // Step 5: Find the city with the smallest number of reachable neighbors
        int ans = 0; // Variable to store the result (city index)
        int count = n; // Initialize with the maximum possible neighbors (worst case)

        for (int i = 0; i < n; i++) {
            int cnt = 0; // Count of neighbors within the distance threshold
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold) cnt++; // Count reachable neighbors
            }

            // Update the result if this city has fewer reachable neighbors,
            // or if there's a tie, prefer the city with the larger index.
            if (cnt <= count) {
                ans = i;  // Update the answer to the current city index
                count = cnt; // Update the minimum neighbor count
            }
        }

        return ans; // Return the city with the smallest number of reachable neighbors
    }
};
