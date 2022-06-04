class Solution {
public:
    //constructing result using the chess board
    vector<string> construct_res(vector<vector<char>> &board){
        vector<string> res;
        for(int i=0;i<board.size();i++){
            string temp="";
            for(auto ch:board[i]){
                temp+=ch;
            }
            res.push_back(temp);
        }
        return res;
    }
    //function to check possible positions for queen
    bool isSafeForQueen(vector<vector<char>> &board, int row, int col){
        for(int i=row-1, j=col; i>=0;i--){
            if(board[i][j]=='Q') return false;
        }
        for(int i=row-1, j=col-1; i>=0 && j>=0;i--, j--){
            if(board[i][j]=='Q') return false;
        }
        for(int i=row-1, j=col+1; i>=0 && j<board.size();i--, j++){
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
    //function to generate all possible outcomes
    void printNqueen(vector<vector<char>> board, int row, vector<vector<string>> &res){
        if(row==board.size()){
            res.push_back(construct_res(board));
            //cout<<qsf<<endl;
            return;
        }
        for(int col=0;col<board[0].size();col++){
            if(isSafeForQueen(board, row, col)==true){
                board[row][col]='Q';
                printNqueen(board, row+1, res);
                board[row][col]='.';
            }
        }
    }
    //main working function
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<vector<char>> board(n, vector<char> (n, '.'));
        //string qsf="";
        printNqueen(board, 0, res);
        return res;
    }
};