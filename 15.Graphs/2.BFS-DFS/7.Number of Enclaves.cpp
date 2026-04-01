/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Example 1:
    Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
    Output: 3
    Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:
    Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
    Output: 0
    Explanation: All 1s are either on the boundary or can reach the boundary. 
*/

class Solution {
public:
    bool isValid(int row, int col, int ROW, int COL){
        return (row>=0 && row<ROW && col>=0 && col<COL);
    }

    void dfs_save1(int row, int col, int &ROWS, int &COLS, vector<vector<int>> &visited, vector<vector<int>> &grid){
        visited[row][col] = true;

        static int dx[4] = {1,-1,0,0};
        static int dy[4] = {0,0,1,-1};
        for(int i=0; i<4; i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if(isValid(nrow, ncol, ROWS, COLS) && grid[nrow][ncol]==1 && !visited[nrow][ncol]){
                dfs_save1(nrow, ncol, ROWS, COLS, visited, grid);
            }
        }  
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        int num_OfBoundedLand = 0;
        int ROWS = grid.size();
        int COLS = grid[0].size();
        vector<vector<int>> visited(ROWS, vector<int>(COLS, false));
        
        for(int i=0; i<ROWS; i++){
            if(grid[i][0] == 1) dfs_save1(i, 0, ROWS, COLS, visited, grid);
            if(grid[i][COLS-1] == 1) dfs_save1(i, COLS-1, ROWS, COLS, visited, grid);
        }
        for(int j=0; j<COLS; j++){
            if(grid[0][j] == 1) dfs_save1(0, j, ROWS, COLS, visited, grid);
            if(grid[ROWS-1][j] == 1) dfs_save1(ROWS-1, j, ROWS, COLS, visited, grid);
        }

        for(int i=0; i<ROWS; i++){
            for(int j=0; j<COLS; j++){
                if(grid[i][j]==1 && !visited[i][j]) num_OfBoundedLand++;
            }
        }

        return num_OfBoundedLand;
    }
};