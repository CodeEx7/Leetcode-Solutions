class Solution {
public:    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0] && DFS(board, i, j, 0, word)){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool DFS(vector<vector<char>> &board, int i, int j, int index, string &word){
        if(index==word.size()) return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[index]) return false;
        
        char temp=board[i][j];
        board[i][j]=' ';
        
        if(DFS(board,i+1,j,index+1,word) ||
            DFS(board,i-1,j,index+1,word) ||
            DFS(board,i,j+1,index+1,word) ||
            DFS(board,i,j-1,index+1,word)) return true;
        
        board[i][j]=temp;
        
        return false;
    }
};