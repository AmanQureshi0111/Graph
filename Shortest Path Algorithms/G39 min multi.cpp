/*
Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.

Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.
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
    int mod = 1e5; // Modulus value to handle large numbers within bounds
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int> dist(100000, INT_MAX); // Distance array to store the minimum steps to reach each node
        dist[start] = 0; // Starting node has 0 steps
        
        queue<pair<int, int>> q; // Queue to perform BFS (step, node)
        q.push({0, start}); // Start with the initial node and 0 steps
        
        while(!q.empty()) {
            auto it = q.front();
            int node = it.second;
            int step = it.first;
            q.pop();
            
            if(node == end) return step; // If we reach the target node, return the steps
            
            for(int num : arr) {
                int adjNode = (node * num) % mod; // Calculate the adjacent node
                if(dist[adjNode] == INT_MAX) { // If the adjacent node is not yet visited
                    q.push({step + 1, adjNode}); // Push the adjacent node to the queue with incremented steps
                    dist[adjNode] = step + 1; // Update the distance array
                }
            }
        }
        
        return -1; // If the target node is not reachable, return -1
    }
};

/**
 * Time Complexity (TC):
 * - The overall time complexity of this implementation is O(N * M) where N is the number of elements in `arr` and M is the modulus value (100000 in this case).
 * - Each node can be visited at most once, and for each node, we check all elements in `arr`.
 * - Therefore, the overall time complexity is O(N * M).

 * Space Complexity (SC):
 * - The space complexity is dominated by the distance array and the queue.
 * - The distance array takes O(M) space where M is the modulus value (100000 in this case).
 * - The queue can hold up to O(M) elements in the worst case.
 * - Therefore, the overall space complexity is O(M).
 */
