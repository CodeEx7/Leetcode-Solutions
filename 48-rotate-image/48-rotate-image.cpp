class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int low=0, high=matrix.size()-1;
        //swapping the rows
        while(low<high){
            for(int i=0;i<matrix[0].size();i++){
                swap(matrix[low][i], matrix[high][i]);
            }
            low++, high--;
        }
        //swapping the values around diagonal
        for(int i=0;i<matrix.size();i++){
            for(int j=i;j<matrix[0].size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        return;
    }
};