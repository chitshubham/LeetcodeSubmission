class Solution {
public:
    int row;
    int col;

    int  solve(int  i , int j , vector<vector<int>>&grid )
    {
        if(j<0 || j==col )  return -1;
        if(i==row) return j;
        if( (grid[i][j] ==1 && j+1<col && grid[i][j+1]==-1) || (j-1>=0 && grid[i][j] == -1 && grid[i][j-1] == 1 )) return -1;
    int  ans = grid[i][j]==1 ? solve(i+1 , j+1 ,grid) : solve(i+1 , j-1 , grid);
        return ans;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
      row = grid.size();
      col = grid[0].size();
      vector<int>ans;
      for(int i = 0; i<col;++i )
      {
        ans.push_back( solve(0 , i , grid));

      }
      return ans;
    }
};