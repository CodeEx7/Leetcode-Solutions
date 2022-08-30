class Solution {
public:
    //to find out the rotation
    void rotation(vector<vector<int>> &mat){
        int low=0, high=mat.size()-1;
        while(low<high){
            for(int i=0;i<mat.size();i++){
                swap(mat[low][i],mat[high][i]);
            }
            low++, high--;
        }        
        for(int i=0;i<mat.size();i++){
            for(int j=i;j<mat[0].size();j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        return;
    }
    
    //function to compare
    bool isEqual(vector<vector<int>>& mat, vector<vector<int>>& target){
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]!=target[i][j])
                    return false;
            }
        }
        return true;
    }
    
    
    //amin working function
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i=0;i<4;i++){
            if(isEqual(mat,target))
                return true;
            else
                rotation(mat);
        }
        return false;
    }
};