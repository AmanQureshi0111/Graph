/*
Given a sorted dictionary of an alien language having some words dict and k starting alphabets of a standard dictionary. Find the order of characters in the alien language. If no valid ordering of letters is possible, then return an empty string.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be "true" if the order of string returned by the function is correct else "false" denotes incorrect string returned.
Examples:

Input: dict[] = ["baa","abcd","abca","cab","cad"], k = 4
Output: true
Explanation: Here order of characters is 'b', 'd', 'a', 'c' Note that words are sorted and in the given language "baa" comes before "abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
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
    string findOrder(vector<string> dict, int k) {
        // create a adj matrix
        // find out which characters comes before in alien dictionary
        // make a edge from prev char to after char
        vector<vector<int>> adj(k);
        for(int i=0;i<dict.size()-1;i++){
            for(int ptr=0;ptr<dict[i].size() && ptr<dict[i+1].size();ptr++){
                if(dict[i][ptr]!=dict[i+1][ptr]){
                    int u=dict[i][ptr]-'a';
                    int v=dict[i+1][ptr]-'a';
                    adj[u].push_back(v);
                    break;
                }
            }
        }
        vector<int> indegree(k,0);
        for(int i=0;i<k;i++){
            for(auto it:adj[i]) indegree[it]++;
        }
        queue<int> q;
        for(int i=0;i<k;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        string ans="";
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node+'a');
            for(auto it:adj[node]){
                if(--indegree[it] == 0) q.push(it);
            }
        }
        return ans;
    }
};