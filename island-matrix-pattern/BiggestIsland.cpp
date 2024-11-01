#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
    /**
     * Biggest Island (easy)
     * 
     * Given a 2D array (i.e., a matrix) containing only 1s (land) and 0s (water), 
     * find the biggest island in it. Write a function to return the area of the biggest island. 
     * 
     * Thinking:
     *      traverse the matrix
     *          if cell (r, c) == 1:
     *              island size = explore(r, c, matrix);
     *              compare with max size
     * 
     *          return max size
     * 
     *      explore(r, c, matrix)
     *          if matrix[r][c] == 0: return 0
     *          let matric[r][c] be 0
     *          let size = 1;
     *          if has up: size += explore up
     *          same for down, left, right
     * 
     *          return size
     */
    int maxAreaOfIsland(vector<vector<int>> &matrix)
    {
        int biggestIslandArea = 0;

        for(int r = 0; r < matrix.size(); r++){
            for (int c = 0; c < matrix.at(r).size(); c++){
                if (matrix.at(r).at(c) == 1){
                    biggestIslandArea = max(explore(r, c, matrix), biggestIslandArea);
                }
            }
        }
        return biggestIslandArea;
    }

    int explore(int r, int c, vector<vector<int>> &matrix){
        if (matrix.at(r).at(c) == 0) return 0;

        matrix.at(r).at(c) = 0;
        int area = 1;

        // top
        if (0 < r && r < matrix.size()) area += explore(r-1, c, matrix);
        // bottom
        if (0 <= r && r < matrix.size()-1) area += explore(r+1, c, matrix);
        //left
        if (0 < c && c < matrix.at(r).size()) area += explore(r, c-1, matrix);
        // right
        if (0 <= c && c < matrix.at(r).size()-1) area += explore(r, c+1, matrix);

        return area;
    }
};