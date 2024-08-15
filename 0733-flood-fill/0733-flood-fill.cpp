class Solution {
public:
   int m,n;
   void solve(vector<vector<int>>&grid , int row , int col ,int color  , int prev,vector<vector<bool>>&visited)
   {
    int dr[]={-1,0,1,0};
   int dc[]= {0,1,0,-1};
      grid[row][col] = color;
      visited[row][col]=true;
     for(int i = 0 ; i<4;++i)
     {
         int nrow = row+dr[i];
         int ncol = col+dc[i];
         if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==prev &&!visited[nrow][ncol])
         {
           solve(grid,nrow,ncol,color,prev,visited);
         }
     }
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        solve(image,sr,sc,color,image[sr][sc],visited);
        return image;
    }
};