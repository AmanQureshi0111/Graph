/*  Time Complexity: The initial traversal + BFS traversal = O(m×n)+O(m×n)=O(m×n).
    Space Compexity: O(mn), for visited matrix and BFS queue.
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
    //row={-1,0,+1,0} up,right,down,left
    //col={0,+1,0,-1}
    void bfs(int sr,int sc,vector<vector<int>> &image,int color,int check,vector<vector<int>> &visited){
        int dir[]={-1,0,+1,0,-1};
        int m=image.size(),n=image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;
        visited[sr][sc]=1;
        while(!q.empty()){
            auto curr=q.front();
            int r=curr.first,c=curr.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dir[i];
                int nc=c+dir[i+1];
                if(nr>=0 && nr<m && nc>=0 && nc<n && image[nr][nc]==check && !visited[nr][nc]){
                    q.push({nr,nc});
                    image[nr][nc]=color;
                    visited[nr][nc]=1;
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int check=image[sr][sc];
        int m=image.size(),n=image[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        bfs(sr,sc,image,color,check,visited);
        return image;
    }
};