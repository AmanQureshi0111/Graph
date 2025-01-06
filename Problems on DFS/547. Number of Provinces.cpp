/*  To find the number connected components
    Time Complexity: O(n2), where n is the number of nodes (size of the adjacency matrix).
    Space Complexity: O(n), for the visited array and recursion stack.
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
public:
    void DFS(vector<vector<int>> isConnected,int node,vector<int> &visited){
        visited[node]=1;
        for(int i=0;i<isConnected.size();i++){
            if(i==node) continue;
            if(isConnected[node][i] && !visited[i]){
                DFS(isConnected,i,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> visited(n,0);
        int provinces=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                provinces++;
                DFS(isConnected,i,visited);
            }
        }
        return provinces;
    }
};