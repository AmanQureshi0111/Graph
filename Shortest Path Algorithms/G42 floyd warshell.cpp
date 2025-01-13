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
    void shortestDistance(vector<vector<int>>& mat) {
        int n = mat.size(); // Number of vertices in the graph
        
        // Step 1: Preprocess the matrix
        // Replace all `-1` entries with a large value (representing infinity) 
        // to indicate no direct path between those vertices.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == -1) mat[i][j] = 1e9; // Treat `-1` as no connection
            }
        }

        // Step 2: Apply the Floyd-Warshall algorithm
        // Iterate through all pairs of vertices and try to update the shortest
        // distance between them using every other vertex as an intermediate node.
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // Update the shortest path from `i` to `j` via `via`
                    mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
                }
            }
        }
        
        // Step 3: Check for negative cycles
        // If any diagonal element becomes negative, it indicates the presence
        // of a negative weight cycle in the graph.
        for (int i = 0; i < n; i++) {
            if (mat[i][i] < 0) {
                // Negative cycle detected
                // Handle this case based on problem requirements
            }
        }

        // Step 4: Postprocess the matrix
        // Replace `1e9` (used as infinity) back with `-1` to indicate no path
        // between those vertices in the final output.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1e9) mat[i][j] = -1; // No connection
            }
        }
    }
};
