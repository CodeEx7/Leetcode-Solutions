class Solution {
public:
    //helper function
    void helpSort(vector<vector<int>> &mat, int row, int col){
        int m=mat.size(), n=mat[0].size();
        vector<int> temp;
        for(int i=row,j=col;i<m && j<n; i++,j++){
            temp.push_back(mat[i][j]);
        }
        sort(temp.begin(),temp.end());
        
        for(int i=row,j=col, k=0;k<temp.size();i++,j++,k++){
            mat[i][j]=temp[k];
        }
    }
    //amin working function
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++){
            helpSort(mat,i,0);
        }
        for(int i=0;i<n;i++){
            helpSort(mat,0,i);
        }
        return mat;
    }
};