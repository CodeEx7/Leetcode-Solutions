class Solution {
public:
    //helper function
    void helpSort(vector<vector<int>> &mat, int row, int col){
        int m=mat.size(), n=mat[0].size();
        vector<int> temp(101,0);
        for(int i=row,j=col;i<m && j<n; i++,j++){
            temp[mat[i][j]]++;
        }
        int i=row,j=col;
        for(int k=1;k<temp.size();k++){
            while(temp[k]>0){
                mat[i][j]=k;
                i++;
                j++;
                temp[k]--;
            }
        }
    }
    //main working function
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