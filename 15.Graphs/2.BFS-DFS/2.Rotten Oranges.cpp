/*

You are given an m x n grid where each cell can have one of three values:
    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.
    Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.



Example 1:
    Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
    Output: 4
    Example 2:

Example 2:
    Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
    Output: -1
    Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
    Example 3:

Example 3:
    Input: grid = [[0,2]]
    Output: 0
    Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
*/ 


class Solution {
public:
    
    bool isValid(int i, int j, int R, int C){
        if(i>=0 && i<R && j>=0 && j<C) return true;
        else return false;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        
        int timeTaken = 0;                                          
        int totalRows = grid.size();
        int totalCols = grid[0].size();


        queue<pair<int,int>> q;
        bool is_freshPresent = false;

        for(int i=0; i<totalRows; i++){                                    
            for(int j=0; j<totalCols; j++){
                if(grid[i][j] == 2) q.push({i,j});
                else if(grid[i][j] == 1) is_freshPresent = true;
            }
        }
        if(!is_freshPresent) return 0;



        while(!q.empty()){
            int totalRotCurrently = q.size();
            bool is_RotSpreaded = false;

            while(totalRotCurrently != 0){
                pair<int,int> parent = q.front();
                q.pop();

                int parentX = parent.first;
                int parentY = parent.second;
                int changeX[4] = {1, -1, 0, 0};
                int changeY[4] = {0, 0, 1, -1};

                for(int i=0; i<4; i++){
                    int adjX = parentX + changeX[i];
                    int adjY = parentY + changeY[i];
                    
                    if(isValid(adjX, adjY, totalRows, totalCols)){
                        if(grid[adjX][adjY] == 1){
                            q.push({adjX, adjY});
                            grid[adjX][adjY] = 0;
                            is_RotSpreaded = true;
                        }
                    }
                }
                totalRotCurrently--;
            }

            if(is_RotSpreaded) timeTaken++;
        }



        for(int i=0; i<totalRows; i++){
            for(int j=0; j<totalCols; j++){
                if(grid[i][j] == 1){
                    timeTaken = -1;
                    break;
                } 
            }
        }

        return timeTaken;
    }
};