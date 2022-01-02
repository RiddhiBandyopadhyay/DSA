class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        //Creating two dummy arrays of rows' and columns' size
        vector<int>dummyRow(rows,-1);
        vector<int>dummyCol(cols,-1);
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j] == 0)
                    dummyRow[i] = dummyCol[j] = 0;
            }
        }
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(dummyRow[i] == 0 or dummyCol[j] == 0)
                    matrix[i][j] = 0;
            }
        }
    }
};