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
     void dfs(int r,int c,vector<vector<int>> &vis,vector<vector<char>> mat){
        vis[r][c]=1;
        int dir[]={-1,0,1,0,-1};
        int m=mat.size(),n=mat[0].size();
        for(int i=0;i<4;i++){
            int nrow=r+dir[i];
            int ncol=c+dir[i+1];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && mat[nrow][ncol]=='O'){
                dfs(nrow,ncol,vis,mat);
            }
        }
    }
public:
    void solve(vector<vector<char>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<char>> res(mat);
        vector<vector<int>> vis(m,vector<int>(n,0));
        //1st row && last row
        for(int i=0;i<n;i++){
            if(!vis[0][i] && mat[0][i]=='O'){
                dfs(0,i,vis,mat);
            }
            if(!vis[m-1][i] && mat[m-1][i]=='O'){
                dfs(m-1,i,vis,mat);
            }
        }
        //1 st col && last col
        for(int i=0;i<m;i++){
            if(!vis[i][0] && mat[i][0]=='O') dfs(i,0,vis,mat);
            if(!vis[i][n-1] && mat[i][n-1]=='O') dfs(i,n-1,vis,mat);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && mat[i][j]=='O') mat[i][j]='X';
            }
        }
    }
};