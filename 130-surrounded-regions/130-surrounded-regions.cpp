class Solution {
public:
    //helper DFS function
    void DFS(vector<vector<char>> &board, int i, int j){
        //general boundry conditions
        if(i<0 ||j<0 ||i>=board.size() || j>=board[0].size()) return;
        if(board[i][j]=='X' || board[i][j]=='#') return;
        
        board[i][j]='#';
        
        DFS(board,i,j+1);
        DFS(board,i+1,j);
        DFS(board,i,j-1);
        DFS(board,i-1,j);        
    }
    
    //main working function
    void solve(vector<vector<char>>& board) {
         int m=board.size(), n=board[0].size();
    //     //for colums check
    //     for(int i=0;i<m;i++){
    //         if(board[i][0]=='O'){
    //             DFS(board,i,0);
    //         }
    //         if(board[i][n-1]=='O'){
    //             DFS(board,i,n-1);
    //         }
    //     }
    //     //for rows check
    //     for(int j=0;j<n;j++){
    //         if(board[0][j]=='O'){
    //             DFS(board,0,j);
    //         }
    //         if(board[0][m-1]=='O'){
    //             DFS(board,m-1,j);
    //         }
    //     }
    
    //Moving over firts and last column   
     for(int i=0; i<m; i++) {
         if(board[i][0] == 'O')
             DFS(board, i, 0);
         if(board[i][n-1] == 'O')
             DFS(board, i, n-1);
     }
        
        
     //Moving over first and last row   
     for(int j=0; j<n; j++) {
         if(board[0][j] == 'O')
             DFS(board, 0, j);
         if(board[m-1][j] == 'O')
             DFS(board, m-1, j);
     }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        
        //checking and updating the values accoding to our changes, if it's # then change it to 'O'(No flip //found) else flip it.
        
        for(int i=0; i<m; i++)
         for(int j=0; j<n; j++)
         {
             if(board[i][j] == 'O')
                 board[i][j] = 'X';
             if(board[i][j] == '#')
                 board[i][j] = 'O';
         }
        
        return;
    }
};