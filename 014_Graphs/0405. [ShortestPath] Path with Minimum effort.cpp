/*
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, 
where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), 
and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). 
You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

Example 1:
    Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
    Output: 2
    Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
    This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
Example 2:
    Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
    Output: 1
    Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
Example 3:
    Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
    Output: 0
    Explanation: T  his route does not require any effort.
 
Constraints:
    rows == heights.length
    columns == heights[i].length
    1 <= rows, columns <= 100
    1 <= heights[i][j] <= 106

*/

class Solution {
public:
    
    typedef pair<int,pair<int,int>> P;

    bool isValid(int i, int j, int R, int C){
        return i>=0 && i<R && j>=0 && j<C;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int ROWS = heights.size();
        int COLS = heights[0].size();

        vector<vector<int>> effort(ROWS, vector<int>(COLS, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, {0,0}});
        effort[0][0] = 0;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        while(!pq.empty()){
            int diff = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x==ROWS-1 && y==COLS-1) return diff;

            for(int i=0; i<4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(isValid(newX, newY, ROWS, COLS)){
                    int newDiff = abs(heights[x][y] - heights[newX][newY]);
                    int maxDiff = max(diff, newDiff);

                    if(effort[newX][newY] > maxDiff){
                        effort[newX][newY] = maxDiff;
                        pq.push({maxDiff, {newX, newY}});
                    }
                }
            }
        }

        return effort[ROWS-1][COLS-1];

    }
};