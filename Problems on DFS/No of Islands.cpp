/*  https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
using namespace std;
void bfs(int x,int y,vector<vector<char>> grid,vector<vector<bool>> &visited){
        int row[]={0,-1,-1,-1,0,1,1,1};
        int col[]={-1,-1,0,1,1,1,0,-1};
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({x,y});
        visited[x][y]=true;
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int r=curr.first,c=curr.second;
            for(int i=0;i<8;i++){
                int nr=r+row[i];
                int nc=c+col[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1' && visited[nr][nc]==false){
                    q.push({nr,nc});
                    visited[nr][nc]=true;
                }
            }
        }
    }
     // Function to find the number of islands.
int numIslands(vector<vector<char>>& grid) {
    int n=grid.size(),m=grid[0].size();
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    int count=0;
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(grid[i][j]=='1' && !visited[i][j]){
                bfs(i,j,grid,visited);
                count++;
            }
            }
    }
     return count;
}