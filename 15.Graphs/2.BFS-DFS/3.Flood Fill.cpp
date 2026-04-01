/*
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].
To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.
Return the modified image after performing the flood fill.

Example : 
    Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
    Output: [[2,2,2],[2,2,0],[2,0,1]]
    Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
    Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
*/

class Solution {
public:

    bool isValid(int &r, int c, int &R, int &C){
        if(r>=0 && r<R && c>=0 && c<C) return true;
        return false;
    }

    void dfs_solver(int x, int y, int &N, int &M, int &srcColor, int &targetColor, vector<vector<bool>> &visited, vector<vector<int>> &arr){    
                
        if(!isValid(x,y,N,M)) return;

        if(visited[x][y]) return;
        else visited[x][y] = true;
        
        if(arr[x][y]==srcColor)arr[x][y] = targetColor;
        else return;
 
        static int addX[] = {1, -1, 0, 0,};
        static int addY[] = {0, 0, 1, -1};
        for(int i=0; i<4; i++){
            int nextX = x + addX[i];
            int nextY = y + addY[i];

            dfs_solver(nextX, nextY, N, M, srcColor, targetColor, visited, arr);   
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int N = image.size();
        int M = image[0].size();
        int srcColor = image[sr][sc];

        vector<vector<bool>> visited(N, vector<bool>(M, false));
        dfs_solver(sr, sc, N, M, srcColor, color, visited, image);

        return image;
    }
};