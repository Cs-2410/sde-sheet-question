class Solution {
private:
       bool ok(int i, int j, vector<vector<char>>& board, char val){
               for(int x = 0; x < 9; x++){
                       if(board[i][x] == val)
                               return false;
                       if(board[x][j] == val)
                               return false;
                       if(board[3*(i/3) + (x/3)][3*(j/3) + (x%3)] == val)
                               return false;
               }
               return true;
       }
        
        bool solve(vector<vector<char>>& board){
                for(int i = 0; i < board.size(); i++){
                       for(int j = 0; j < board[0].size(); j++){
                               if(board[i][j] == '.'){
                             for(char val = '1'; val <= '9'; val++){
                                           if(ok(i , j , board , val)){
                                                 board[i][j] = val;
                                                 if(solve(board))
                                                         return true;
                                                   else
                                                         board[i][j] = '.';
                                           }    
                                       }
                                       return false;
                               }
                       }
                }
                return true;
        }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};