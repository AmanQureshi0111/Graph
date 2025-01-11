/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
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
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q; // Queue for BFS: {word, steps}
        q.push({beginWord, 1});
        
        // Unordered set for fast lookup of word list
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord); // Remove the starting word to avoid revisiting

        while (!q.empty()) {
            string word = q.front().first; // Current word
            int steps = q.front().second; // Current step count
            q.pop();
            
            // If we reach the end word, return the step count
            if (word == endWord) return steps;

            // Generate all possible transformations
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    // If the transformed word is in the set
                    if (st.find(word) != st.end()) {
                        q.push({word, steps + 1});
                        st.erase(word); // Mark the word as visited
                    }
                }
                word[i] = original; // Restore the original word
            }
        }
        
        return 0; // If no transformation sequence exists
    }
};

/*
Time Complexity:
1. Initialization of unordered set: O(n), where n is the size of the wordList.
2. BFS traversal: O(n * m * log n), where:
   - n is the number of words in wordList.
   - m is the length of each word.
   - log n comes from the average complexity of set operations (insert/find/erase).
Overall: O(n * m * log n).

Space Complexity:
1. Queue for BFS: O(n).
2. Unordered set: O(n).
3. Temporary variables: O(m).
Overall: O(n + m).
*/
