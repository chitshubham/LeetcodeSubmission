class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int  row = matrix.size();
        int col = matrix[0].size();
        vector<bool>isRowzero(row,false);
        vector<bool>isColzero(col,false);
        for(int i =0;i<row;++i){
            for(int j = 0; j <col;++j){
                 if(matrix[i][j]==0) {
                    isRowzero[i] = true;
                    isColzero[j] = true;
                 }
            }
        }
        for(int i = 0; i< row;++i){
           for(int j = 0; j<col;++j){
            if(isRowzero[i] || isColzero[j]) matrix[i][j]=0;
           }
        }
    }
};