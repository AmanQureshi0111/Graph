/*
    return shortest paths of transformation
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
class Solution {
private:
    void dfs(string word, vector<string> &seq) {
        if(word == b) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = mp[word];
        for(int i = 0; i < sz; i++) {
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if(mp.find(word) != mp.end() && mp[word] == steps - 1) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }
public:
    unordered_map<string, int> mp;
    vector<vector<string>> ans;
    string b;
    int sz;
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        b = beginWord;
        queue<string> q;
        q.push(beginWord);
        mp[beginWord] = 0;
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        sz = beginWord.size();
        while(!q.empty()) {
            string word = q.front();
            int steps = mp[word];
            q.pop();

            if(word == endWord) break;

            for(int i = 0; i < sz; i++) {
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if(st.find(word) != st.end()) {
                        q.push(word);
                        mp[word] = steps + 1;
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        if(mp.find(endWord) != mp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }
};

/**
 * Time Complexity (TC):
 * - The BFS (Breadth-First Search) part of the algorithm takes O(N * M * 26) where N is the length of the wordList,
 *   M is the length of each word, and 26 represents the number of possible characters (a-z) for each position in the word.
 * - The DFS (Depth-First Search) part of the algorithm is complex to analyze due to the branching factor, 
 *   but generally, it can take O(M * |V|) where |V| is the number of vertices in the graph.
 * - Overall, the complexity is approximately O(N * M * 26) for BFS and potentially exponential for DFS in the worst case.

 * Space Complexity:
 * - The space complexity is dominated by the BFS queue and the DFS recursion stack.
 * - BFS queue can hold up to O(N) words in the worst case.
 * - DFS recursion stack can go as deep as O(M * |V|) in the worst case.
 * - Additionally, the map `mp` can store up to O(N) words with their steps.
 * - The set `st` is used to store the wordList, thus taking O(N) space.
 * - Overall, the space complexity is O(N) due to the data structures used.
 */
