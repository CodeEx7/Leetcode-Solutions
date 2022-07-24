class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int column=matrix[0].size()-1;
        int row=0;
        while(column>=0 && row<matrix.size()){
            if(matrix[row][column]>target){
                column--;
            }else if(matrix[row][column]<target){
                row++;
            }else{
                return true;
            }
        }
        return false;
    }
};