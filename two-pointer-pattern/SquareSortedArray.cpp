#include <iostream>
#include <vector>

class Solution
{
    public:

    /**
     * Squaring a Sorted Array (easy)
     * 
     * Given a sorted array, create a new array containing squares of all the numbers of the input array in the sorted order.
     * 
     * Example 1:
     *      Input: [-2, -1, 0, 2, 3]
     *      Output: [0, 1, 4, 4, 9]
     * 
     * Time Complexity:
     * Space Complexity:
     * 
     * Pointer 1: start
     * Pointer 2: end
     * 
     * Logic:
     *      If negative and positive: largest squares will be at either end
     *      If negative only: largest squares at the start
     *      If positive only: largest squares at the end
     * 
     *      Start by looking at the two ends, find the larger of the 2 square values
     *      This is guaranteed to be the largest square in the set -> place it at the end of the sorted squares list
     *      Increment front or decrement back depending on which one you "consumed"
     *      Compare the next 2 elements from the end
     *      Continue until the two pointers meet
    */
    static std::vector<int> sortedSquares( const std::vector<int> & arr ) {
        int frontIdx = 0;
        int backIdx = arr.size() -1;

        std::vector<int> squares {};
        squares.resize(arr.size());
        int insertIdx = squares.size() -1;

        while ( frontIdx <= backIdx ) {
            int front = arr.at(frontIdx) * arr.at(frontIdx);
            int back = arr.at(backIdx) * arr.at(backIdx);
            if ( front > back ) {
                // Add front square
                squares.at(insertIdx--) = front;
                frontIdx++;
            } else {
                // Add back square
                squares.at(insertIdx--) = back;
                backIdx--;
            }
        }
        return squares;
    }
};

