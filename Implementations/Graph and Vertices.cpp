class Solution {
  public:
    long long count(int n) {
        long long E=(n*(n-1))/2; //no of edges
        return 1LL<<E; //2^E = no of graph
    }
};
/*  Given an integer n representing number of vertices. Find out how many undirected graphs (not necessarily connected) can be constructed out of a given n number of vertices.
*/
/*  no of edges(E)= nC2 = n(n-1)/2
    no of graph   = 2^E = 1<<E
 */