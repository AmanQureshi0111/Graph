/* DAG-Directed Acyclic Graph by topoSort

*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
using namespace std;
class Solution {
  private:
    // Helper function for DFS to generate topological order
    void dfs(int node, vector<int>& vis, vector<vector<pair<int, int>>> adj, stack<int>& topoSort) {
        vis[node] = 1;
        for (auto adjNode : adj[node]) {
            if (!vis[adjNode.first]) dfs(adjNode.first, vis, adj, topoSort);
        }
        topoSort.push(node);
    }

  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Adjacency list representation of the graph
        vector<vector<pair<int, int>>> adj(V);
        for (auto edge : edges) {
            int u = edge[0], v = edge[1], d = edge[2];
            adj[u].push_back({v, d});
        }

        // Step 1: Create topological sort
        stack<int> topoSort;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, topoSort);
            }
        }

        // Step 2: Remove node from stack and update distances
        vector<int> dis(V, INT_MAX);
        dis[0] = 0;

        // Relax edges in topological order
        while (!topoSort.empty()) {
            int node = topoSort.top();
            topoSort.pop();
            if (dis[node] != INT_MAX) {
                for (auto adjNode : adj[node]) {
                    dis[adjNode.first] = min(dis[adjNode.first], dis[node] + adjNode.second);
                }
            }
        }

        // Replace unreachable distances with -1
        for (int i = 0; i < V; i++) {
            if (dis[i] == INT_MAX) dis[i] = -1;
        }

        return dis;
    }
};

/*
Time Complexity:
1. Building the adjacency list: O(E), where E is the number of edges.
2. Topological sorting (DFS): O(V + E), where V is the number of vertices.
3. Relaxation of edges: O(E).
Overall: O(V + E).

Space Complexity:
1. Adjacency list: O(V + E).
2. Visited array: O(V).
3. Topological stack: O(V).
4. Distance array: O(V).
Overall: O(V + E).
*/
