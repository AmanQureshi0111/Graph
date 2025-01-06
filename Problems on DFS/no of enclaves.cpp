/*  Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
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
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0 || i==m-1 || j==n-1){
                    if(grid[i][j]==1){
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }
        int dir[]={-1,0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            for(int i=0;i<4;i++){
                int nrow=row+dir[i];
                int ncol=col+dir[i+1];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
            q.pop();
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]) cnt++;
            }
        }
        return cnt;
    }
};