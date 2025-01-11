// You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

// You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

// Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.
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
    // Use long long instead of int
    #define ll long long
    ll mod = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll, ll>>> adj(n);
        for(auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]}); // Add edge it[0] -> it[1] with weight it[2]
            adj[it[1]].push_back({it[0], it[2]}); // Add edge it[1] -> it[0] with weight it[2] (undirected graph)
        }

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
        q.push({0, 0}); // Start with distance 0 from node 0

        vector<ll> dist(n, LLONG_MAX); // Distance array, initialized to infinity
        dist[0] = 0; // Distance to the starting node is 0

        vector<ll> ways(n, 0); // Ways array to count the number of ways to reach each node
        ways[0] = 1; // There's one way to reach the starting node (from itself)

        while(!q.empty()) {
            auto it = q.top();
            q.pop();

            ll node = it.second;
            ll d = it.first;

            for(auto it : adj[node]) {
                ll adjNode = it.first;
                ll edgeWeight = it.second;

                // If a shorter path to adjNode is found
                if(dist[adjNode] > d + edgeWeight) {
                    dist[adjNode] = d + edgeWeight; // Update the distance to adjNode
                    ways[adjNode] = ways[node]; // Update the number of ways to reach adjNode
                    q.push({dist[adjNode], adjNode}); // Push the updated distance and node
                } else if(dist[adjNode] == d + edgeWeight) {
                    // If another shortest path to adjNode is found
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod; // Add the number of ways to reach adjNode
                }
            }
        }
        return ways[n-1]; // Return the number of ways to reach the last node
    }
};

/**
 * Time Complexity (TC):
 * - The overall time complexity of this implementation is O((N + M) * logN) where N is the number of nodes and M is the number of edges.
 * - Constructing the adjacency list takes O(M) time.
 * - Each operation in the priority queue (push and pop) takes O(logN) time.
 * - The while loop runs N times, and within each loop, the for loop runs M times.
 * - Therefore, the overall time complexity is O((N + M) * logN).

 * Space Complexity (SC):
 * - The space complexity is dominated by the priority queue and the distance and ways arrays.
 * - The priority queue can hold up to O(N) nodes in the worst case.
 * - The distance and ways arrays each take O(N) space.
 * - Therefore, the overall space complexity is O(N + M).
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
#include<fstream> // Include fstream for logging
using namespace std;

class Solution {
public:
    // Use long long instead of int
    #define ll long long
    ll mod = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll, ll>>> adj(n);
        for(auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]}); // Add edge it[0] -> it[1] with weight it[2]
            adj[it[1]].push_back({it[0], it[2]}); // Add edge it[1] -> it[0] with weight it[2] (undirected graph)
        }

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
        q.push({0, 0}); // Start with distance 0 from node 0

        vector<ll> dist(n, LLONG_MAX); // Distance array, initialized to infinity
        dist[0] = 0; // Distance to the starting node is 0

        vector<ll> ways(n, 0); // Ways array to count the number of ways to reach each node
        ways[0] = 1; // There's one way to reach the starting node (from itself)

        while(!q.empty()) {
            auto it = q.top();
            q.pop();

            ll node = it.second;
            ll d = it.first;

            for(auto it : adj[node]) {
                ll adjNode = it.first;
                ll edgeWeight = it.second;

                // If a shorter path to adjNode is found
                if(dist[adjNode] > d + edgeWeight) {
                    dist[adjNode] = d + edgeWeight; // Update the distance to adjNode
                    ways[adjNode] = ways[node]; // Update the number of ways to reach adjNode
                    q.push({dist[adjNode], adjNode}); // Push the updated distance and node
                } else if(dist[adjNode] == d + edgeWeight) {
                    // If another shortest path to adjNode is found
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod; // Add the number of ways to reach adjNode
                }
            }
        }
        return ways[n-1]; // Return the number of ways to reach the last node
    }
};

/**
 * Time Complexity (TC):
 * - The overall time complexity of this implementation is O((N + M) * logN) where N is the number of nodes and M is the number of edges.
 * - Constructing the adjacency list takes O(M) time.
 * - Each operation in the priority queue (push and pop) takes O(logN) time.
 * - The while loop runs N times, and within each loop, the for loop runs M times.
 * - Therefore, the overall time complexity is O((N + M) * logN).

 * Space Complexity (SC):
 * - The space complexity is dominated by the priority queue and the distance and ways arrays.
 * - The priority queue can hold up to O(N) nodes in the worst case.
 * - The distance and ways arrays each take O(N) space.
 * - Therefore, the overall space complexity is O(N + M).
 */
