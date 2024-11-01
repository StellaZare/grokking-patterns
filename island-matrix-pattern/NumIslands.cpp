#include <iostream>
#include <vector>

class NumOfIslandsBFS
{
    public:
    /**
     * Number of Islands (easy)
     * 
     * Given a 2D array (i.e., a matrix) containing only 1s (land) and 0s (water), 
     * count the number of islands in it.
     * 
     * An island is a connected set of 1s (land) and is surrounded by either an edge or 0s (water). 
     * Each cell is considered connected to other cells horizontally or vertically (not diagonally).
     */
    int countIslands(std::vector<std::vector<int>> &matrix){
        int totalIslands = 0;
        
        for(int row = 0; row < matrix.size(); row++){
            for(int col = 0; col < matrix.at(row).size(); col++){
                if( matrix.at(row).at(col) == 1){
                    explore(row, col, matrix);
                    totalIslands++;
                }
            }
        }
        return totalIslands;
    }

    void explore(int r, int c, std::vector<std::vector<int>> &matrix){
        if (matrix.at(r).at(c) == 0)
            return;
        
        int rows = matrix.size();
        int cols = matrix.at(0).size();
        matrix.at(r).at(c) = 0;

        // visit top
        if (r >= 1 && r < rows) explore(r-1, c, matrix);
        // visit bottom
        if (r >= 0 && r < rows-1) explore(r+1, c, matrix);

        // visit left
        if (c >= 1 && c < cols) explore(r, c-1, matrix);
        // visit right
        if (c >= 0 && c < cols-1) explore(r, c+1, matrix);
    }
};

int main(int argc, char **argv)
{
    NumOfIslandsBFS islands;
	std::vector<std::vector<int>>  vec = std::vector<std::vector<int>>{
        {1, 1, 1, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}};
    std::cout << islands.countIslands(vec) << std::endl;

    vec = {
        {0, 1, 0, 1, 0}};
    std::cout << islands.countIslands(vec) << std::endl;

    return 0;
};