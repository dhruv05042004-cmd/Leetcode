class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board) {
        // Find an empty cell
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == '.') 
                {
                    // Try numbers 1 to 9
                    for(char c = '1'; c <= '9'; c++) {
                        // Check if placing c is valid
                        if(isValid(board, i, j, c)) 
                        {
                            // Place the number
                            board[i][j] = c;
                            // Recursively solve the rest
                            if(solve(board))
                                return true;
                            // Backtrack
                            board[i][j] = '.';
                        }
                    }
                    // No number worked for this cell
                    return false;
                }
            }
        }
        // No empty cells → Sudoku solved
        return true;
    }
    bool isValid(vector<vector<char>>& board,int row,int col,char c) {
        for(int i = 0; i < 9; i++) 
        {
            // Check column
            if(board[i][col] == c)
                return false;
            // Check row
            if(board[row][i] == c)
                return false;
            // Check 3x3 box
            if(board[3 * (row / 3) + i / 3]
                    [3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }
};