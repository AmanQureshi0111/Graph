/*Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

 

Example 1:

Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
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

class DSU{
    private:
        vector<int> par,size;
    public:
        DSU(int n){
            size.resize(n,1);
            par.resize(n);
            for(int i=0;i<n;i++) par[i]=i;
        }
        int find(int x){
            if(x==par[x]) return x;
            return par[x]=find(par[x]);
        }
        void Union(int x,int y){
            int yp=find(y);
            int xp=find(x);
            if(xp==yp) return;
            if(size[yp]>size[xp]){
                par[xp]=yp;
                size[yp]+=size[xp];
            }else{
                par[yp]=xp;
                size[xp]+=size[yp];
            }
        }
    };
    class Solution {
    public:
        vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
            int n=accounts.size();
            unordered_map<string,int> mp;
            DSU ds(n);
            for(int i=0;i<n;i++){
                for(int j=1;j<accounts[i].size();j++){
                    string mail=accounts[i][j];
                    if(mp.find(mail)==mp.end()){
                        mp[mail]=i;
                    }else{
                        ds.Union(i,mp[mail]);
                    }
                }
            }
            vector<vector<string>> mergedAcc(n);
            for(auto it:mp){
                int idx    =ds.find(it.second);
                string mail=it.first;
                mergedAcc[idx].push_back(mail);
            }
    
            vector<vector<string>> ans;
            for(int i=0;i<n;i++){
                if(mergedAcc[i].empty()) continue;
                string name=accounts[i][0];
                sort(mergedAcc[i].begin(),mergedAcc[i].end());
                vector<string> vec;
                vec.push_back(name);
                for(string mail:mergedAcc[i]) vec.push_back(mail);
                ans.push_back(vec);
            }
    
            return ans;
        }
    };

/*
1.  Create a DSU class with Union and Find methods.
2.  Iterate over each account and for each email, check if it's already in the map
If not, add it to the map with the current account index as its parent.
If it is, merge the two accounts using the Union method.
3.  After iterating over all accounts, iterate over the map and for each email, find its
parent index using the Find method and add it to the corresponding merged account list.
4.  Finally, iterate over the merged account lists and for each list, add the name of
the first account and sort the list of emails before adding it to the result.
*/
