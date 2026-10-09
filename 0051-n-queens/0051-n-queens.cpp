class Solution {
public:
    void solve(int col,
               vector<string>& board,
               vector<vector<string>>& ans,
               vector<int>& leftRow,
               vector<int>& upperDiagonal,
               vector<int>& lowerDiagonal,
               int n)
    {
        // All columns are filled
        if(col == n)
        {
            ans.push_back(board);
            return;
        }
        // Try placing queen in every row of this column
        for(int row = 0; row < n; row++)
        {
            // Check if the position is safe
            if(leftRow[row] == 0 &&
               lowerDiagonal[row + col] == 0 &&
               upperDiagonal[n - 1 + col - row] == 0)
            {
                // Place queen
                board[row][col] = 'Q';
                // Mark row and diagonals
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                // Move to next column
                solve(col + 1,
                      board,
                      ans,
                      leftRow,
                      upperDiagonal,
                      lowerDiagonal,
                      n);
                // BACKTRACK: remove queen
                board[row][col] = '.';
                // Unmark row and diagonals
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        // Create empty board
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        // Track occupied rows
        vector<int> leftRow(n, 0);
        // Track occupied diagonals
        vector<int> upperDiagonal(2 * n - 1, 0);
        vector<int> lowerDiagonal(2 * n - 1, 0);
        // Start from column 0
        solve(0,
              board,
              ans,
              leftRow,
              upperDiagonal,
              lowerDiagonal,
              n);
        return ans;
    }
};