/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.
Example 1:
    Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
    Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:
    Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
    Output: [[0,0,0],[0,1,0],[1,2,1]]
Constraints:
    m == mat.length
    n == mat[i].length
    1 <= m, n <= 104
    1 <= m * n <= 104
    mat[i][j] is either 0 or 1.
    There is at least one 0 in mat.
*/

// TimeLimitExceded Solution (Single source BFS): 
/*
0.  We will require v<v<i>>res, v<b>visited, q<p<i,i>>q;
1.  Traverse the matrix, since we have to find nearest zero, 
2.  If val==0, put 0 in res.
    Else if val==1, bfs to find nearest dist to reach 0 for that location, and put in res.
*/
class Solution {
public:

    bool isValid(int i, int j, int R, int C){
        if(i>=0 && i<R && j>=0 && j<C) return true;
        return false;
    }
    void bfs_fillDistanceOfNearestZero(int currR, int currC, int &ROWS, int &COLS, vector<vector<int>> &mat, vector<vector<int>> &res){
        
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));

        q.push({currR, currC});
        visited[currR][currC] = true;
        
        int addX[] = {1, -1, 0, 0};
        int addY[] = {0, 0, 1, -1};  
        int nearestZeroDist = 1;
        while(!q.empty()){                                                                               // since there is atleast one '0'
            int qSize = q.size();
            
            for(int currItr=0; currItr<qSize; currItr++){

                pair<int,int> front = q.front();
                q.pop();
                int parentX = front.first;
                int parentY = front.second;

                for(int i=0; i<4; i++){
                    int newX = parentX + addX[i];
                    int newY = parentY + addY[i];

                    if(isValid(newX, newY, ROWS, COLS)){
                        if(mat[newX][newY]==0){
                            res[currR][currC] = nearestZeroDist;
                            return;
                        }
                        else if(!visited[newX][newY]){
                            visited[newX][newY] = true;
                            q.push({newX, newY});
                        } 
                    }
                }
            }
            
            nearestZeroDist++;
        }

    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n));

        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int val = mat[i][j];

                if(val == 0){
                    res[i][j] = 0;
                }
                else bfs_fillDistanceOfNearestZero(i, j, m, n, mat, res);
            }
        }

        return res;
    }
};



// Better Solution (Multi source BFS) : 
/*
0.  We will require , v<v<i>>res, v<b>visited, q<p<p<i,i>>, i>q;
1.  Traverse the matrix, since we have to find nearest zero,
2.  If val==0, put ({<i,j>, 0}) in q, and mark visited.
    Else val==1, do nothing
3.
*/
class Solution {
public:

    bool isValid(int &i, int &j, int &R, int &C){
        return (i>=0 && i<R && j>=0 && j<C);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<pair<int,int>, int>> q;                                 // {{i,j}, steps}

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j}, 0});
                    visited[i][j] = true;
                }
            }
        }

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            res[row][col] = steps;

            for(int i=0; i<4; i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];

                if(isValid(nrow, ncol, m, n) && !visited[nrow][ncol]){
                    q.push({{nrow, ncol}, steps+1});
                    visited[nrow][ncol] = true;
                }
            }

        }

        return res;
    }
};

// Optimal Solution (DP) : 
