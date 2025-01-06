#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
using namespace std;
class Solution {
  private:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>> &grid,vector<pair<int,int>> &vec,int row0,int col0){
        vis[row][col]=1;
        vec.push_back({row-row0,col-col0});
        int m=grid.size(),n=grid[0].size();
        int dir[]={-1,0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+dir[i];
            int ncol=col+dir[i+1];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,vis,grid,vec,row0,col0);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        set<vector<pair<int,int>>> st;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>> vec;
                    dfs(i,j,vis,grid,vec,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};