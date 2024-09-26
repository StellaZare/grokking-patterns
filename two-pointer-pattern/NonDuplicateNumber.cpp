#include <iostream>
#include <vector>

class Solution
{
public:
    /**
     * Find Non-Duplicate Number Instances (easy)
     *
     * Given an array of sorted numbers, move all non-duplicate number instances at the beginning of the array in-place.
     * The non-duplicate numbers should be sorted and you should not use any extra space.
     *
     * Move all the unique number instances at the beginning of the array and after moving
     * return the length of the subarray that has no duplicate in it.
     *
     * Time Complexity: O(N)
     * Space Complexity: O(1)
     *
     * Pointer 1: index to insert unique elements
     * Pointer 2: index to check
     *
     */
    int moveElements(std::vector<int> &arr)
    {
        if (arr.size() == 0)
            return 0;

        int insertIdx = 1;

        for (int checkIdx = 1; checkIdx < arr.size(); checkIdx++)
        {
            if (arr.at(checkIdx) != arr.at(checkIdx - 1))
            {
                // Looking at a new value -> move up
                arr.at(insertIdx++) = arr.at(checkIdx);
            }
        }
        return insertIdx;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    std::vector<int> one = {1};
    std::vector<int> empty = {};

    std::vector<int> v1 = {1, 2, 2, 2, 3, 3, 4, 6};
    std::vector<int> v2 = {2, 5, 9, 11};
    std::vector<int> v3 = {5, 5, 5, 5};

    std::cout << "Array new length: " << sol.moveElements(one) << std::endl;
    std::cout << "Array new length: " << sol.moveElements(empty) << std::endl;
    std::cout << "Array new length: " << sol.moveElements(v1) << std::endl;
    std::cout << "Array new length: " << sol.moveElements(v2) << std::endl;
    std::cout << "Array new length: " << sol.moveElements(v3) << std::endl;
}