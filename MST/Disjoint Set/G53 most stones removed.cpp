/*
947. Most Stones Removed with Same Row or Column
Solved
Medium
Topics
Companies
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

 

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
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

class DisjointSet{
private:
    vector<int> parent,size;
public:
    DisjointSet(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y){
        int yP=find(x);
        int xP=find(y);
        if(xP==yP) return;
        if(size[yP]>size[xP]){
            parent[xP]=yP;
            size[yP]+=size[xP];
        }else{
            parent[yP]=xP;
            size[xP]+=size[yP];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxRows=INT_MIN;
        int maxCols=INT_MIN;
        for(auto it:stones){
            maxRows=max(maxRows,it[0]);
            maxCols=max(maxCols,it[1]);
        }
        unordered_set<int> st;
        DisjointSet ds(maxRows+maxCols+2);
        for(auto it:stones){
            int rowNode=it[0];
            int colNode=it[1]+maxRows+1;
            ds.Union(rowNode,colNode);
            st.insert(rowNode);
            st.insert(colNode);
        }
        int cnt=0;
        for(auto x:st){
            if(ds.find(x)==x) cnt++;
        }

        return n-cnt;
    }
};