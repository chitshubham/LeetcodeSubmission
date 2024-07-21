class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size() , n = matrix[0].size();
        vector<int>row(m,0);
        vector<int>col(n,0);
        for(int i = 0;i<m;++i)
        {
            int mini = INT_MAX;
            for(int j = 0;j<n;++j)
            {
                mini = min(mini,matrix[i][j]);
            }
            row[i] = mini;
        }
        for(int j = 0; j<n;++j )
        {
            int maxi = 0;
            for(int i =0;i<m;++i)
            {
                maxi = max(maxi,matrix[i][j]);
            }
            col[j] = maxi;
         
        }
        vector<int>ans;
        for(int i = 0; i<m;++i)
        {
            for(int j = 0;j<n;++j)
            {
                if(matrix[i][j]==row[i]&&matrix[i][j]==col[j]) 
                {
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;

    }

};