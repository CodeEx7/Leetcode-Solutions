class Solution {
public:
    //to check that is this position is valid or not
    bool isValidPosForQueen(vector<vector<int>> &chess, int row, int col){
        for(int i=row-1, j=col;i>=0;i--){
            if(chess[i][j]==1) return false;
        }
        for(int i=row-1, j=col-1;i>=0 && j>=0;i--, j--){
            if(chess[i][j]==1) return false;
        }
        for(int i=row-1, j=col+1;i>=0 && j<chess.size();i--, j++){
            if(chess[i][j]==1) return false;
        }
        return true;
    }
    //to count the number of available solution
    void countSol(vector<vector<int>> &chess, int &cnt, int row){
        if(row==chess.size()){
            cnt++;
            return;
        }
        for(int col=0;col<chess[0].size();col++){
            if(isValidPosForQueen(chess, row, col)==true){
                chess[row][col]=1;
                countSol(chess, cnt, row+1);
                chess[row][col]=0;
            }
        }
    }
    //main working function
    int totalNQueens(int n) {
        vector<vector<int>> chess(n, vector<int>(n,0));
        int cnt=0;
        countSol(chess, cnt , 0);
        return cnt;
    }
};