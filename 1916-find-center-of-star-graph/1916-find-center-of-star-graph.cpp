class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>>adjList(n+2);
        for(int i = 0;i<n;++i)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        for(int i =0;i<=n+1;++i)
        {
            if(adjList[i].size()==n) return i;
           
        }
        return -1;
    }
};