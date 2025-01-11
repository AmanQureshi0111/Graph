/*  You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

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
//priority_queue
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(); // Number of rows in the grid
        int cols = heights[0].size(); // Number of columns in the grid

        // Min-heap to store the (effort, cell) pairs
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minH;
        minH.push({0, {0, 0}}); // Starting cell with 0 effort

        vector<vector<int>> diff(rows, vector<int>(cols, INT_MAX)); // Matrix to store the minimum effort to reach each cell
        diff[0][0] = 0; // Starting cell has 0 effort

        int dir[] = {-1, 0, 1, 0, -1}; // Direction vectors for 4-directional movement

        while (!minH.empty()) {
            auto it = minH.top();
            minH.pop();

            int row = it.second.first;
            int col = it.second.second;

            // If we reach the bottom-right cell, return the effort
            if (row == rows - 1 && col == cols - 1) {
                return it.first;
            }

            for (int i = 0; i < 4; i++) {
                int nrow = row + dir[i];
                int ncol = col + dir[i + 1];

                // Check if the new cell is within bounds and if the effort to reach it can be minimized
                if (nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && 
                    diff[nrow][ncol] > max(it.first, abs(heights[nrow][ncol] - heights[row][col]))) {
                    minH.push({max(abs(heights[nrow][ncol] - heights[row][col]), it.first), {nrow, ncol}});
                    diff[nrow][ncol] = max(abs(heights[nrow][ncol] - heights[row][col]), it.first);
                }
            }
        }
        return 0;
    }
};

/**
 * Time Complexity (TC):
 * - The overall time complexity of this implementation is O(N * M * log(N * M)) where N is the number of rows and M is the number of columns.
 * - Each cell can be added to the priority queue at most once with an operation of O(log(N * M)).
 * - We iterate over 4 possible directions from each cell.
 * - Therefore, the overall time complexity is O(N * M * log(N * M)).

 * Space Complexity (SC):
 * - The space complexity is dominated by the priority queue and the diff matrix.
 * - The priority queue can hold up to O(N * M) cells.
 * - The diff matrix takes O(N * M) space.
 * - Therefore, the overall space complexity is O(N * M).
 */


//set
class Solution {
public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        int dir[] = {-1, 0, 1, 0, -1}; // Direction vectors for 4-directional movement
        
        set<pair<int, pair<int, int>>> st; // Set to store the minimum effort and cell coordinates
        st.insert({0, {0, 0}}); // Starting cell with 0 effort
        
        vector<vector<int>> diff(rows, vector<int>(columns, INT_MAX)); // Matrix to store the minimum effort to reach each cell
        diff[0][0] = 0; // Starting cell has 0 effort
        
        while(!st.empty()) {
            auto it = *(st.begin()); // Extract the cell with the minimum effort
            int effort = it.first;
            int row = it.second.first;
            int col = it.second.second;
            st.erase(it); // Remove the cell from the set
            
            for(int i = 0; i < 4; i++) {
                int nrow = row + dir[i];
                int ncol = col + dir[i + 1];
                
                // Check if the new cell is within bounds and if the effort to reach it can be minimized
                if(nrow >= 0 && ncol >= 0 && nrow < rows && ncol < columns) {
                    int e = max(abs(heights[nrow][ncol] - heights[row][col]), effort);
                    if(e < diff[nrow][ncol]) {
                        if(diff[nrow][ncol] != INT_MAX) st.erase({diff[nrow][ncol], {nrow, ncol}});
                        diff[nrow][ncol] = e;
                        st.insert({e, {nrow, ncol}});
                    }
                }
            }
        }
        return diff[rows-1][columns-1]; // Return the minimum effort to reach the bottom-right cell
    }
};

/**
 * Time Complexity (TC):
 * - The overall time complexity of this implementation is O(N * M * log(N * M)) where N is the number of rows and M is the number of columns.
 * - Each cell can be added to the set at most once with an operation of O(log(N * M)).
 * - We iterate over 4 possible directions from each cell.
 * - Therefore, the overall time complexity is O(N * M * log(N * M)).

 * Space Complexity (SC):
 * - The space complexity is dominated by the set and the diff matrix.
 * - The set can hold up to O(N * M) cells.
 * - The diff matrix takes O(N * M) space.
 * - Therefore, the overall space complexity is O(N * M).
 */
