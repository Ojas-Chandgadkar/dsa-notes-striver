/*

Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.
Example 1:
    Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
    Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Example 2:
    Input: board = [["X"]]
    Output: [["X"]]
*/

class Solution {
public:
    bool isValid(int &i, int &j, int &R, int &C){
        return (i>=0 && i<R && j>=0 && j<C);
    }
    void dfs_saveO(int row, int col, int &ROWS, int &COLS, vector<vector<char>> &board){
        board[row][col] = 'S';                                  // S -> marked 'O' as safe

        static int dx[4] = {1,-1,0,0};
        static int dy[4] = {0,0,1,-1};
        for(int i=0; i<4; i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if(isValid(nrow,ncol,ROWS,COLS) && board[nrow][ncol]=='O'){
                dfs_saveO(nrow, ncol, ROWS, COLS, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0; i<m; i++){
            if(board[i][0] == 'O') dfs_saveO(i, 0, m , n, board);
            if(board[i][n-1] == 'O') dfs_saveO(i, n-1, m , n, board);
        
        }
        for(int i=0; i<n; i++){
            if(board[0][i]=='O') dfs_saveO(0, i, m , n, board);
            if(board[m-1][i]=='O') dfs_saveO(m-1, i, m , n, board);
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='S') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }

    }
};

/*
0.  Traverse only border, as only 'O' chain connected to a border can be saved, all others are coverd in four direction by 'X'.
    Do dfs on border when value 'O', such that 'O' chain must form (These are safe, mark as 'S' temporarily)
1.  Traverse entire board, mark 'S' to 'O' and remaining values to 'X'.
*/