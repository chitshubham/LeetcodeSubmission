class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
         vector<long long >degree(n,0);
         

            for(auto it : roads)
            {
                int u = it[0];
                int v = it[1];
                degree[u]++;
                degree[v]++;
            }
            long long  ans = 0;
            long long value =1;
            sort(degree.begin(),degree.end());
            for(long long d : degree )
            {
                ans+=(value*d);
                value++;
            }
            return ans;

    }
};