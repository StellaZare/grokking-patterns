#include <iostream>
#include <vector>

class Solution {

  public:

    /**
     * Pair with Target Sum (easy)
     * Given an array of numbers sorted in ascending order and a target sum, 
     * find a pair in the array whose sum is equal to the given target.
     * 
     * Write a function to return the indices of the two numbers 
     * (i.e. the pair) such that they add up to the given target. 
     * If no such pair exists return [-1, -1].
     * 
     * Time complexity: O(N)
     * Space complexity: O(1)
     * 
     * Pointer 1: start
     * Pointer 2: end
     * 
     * Logic:
     *      Add the first and last elements in the sorted list
     *      If the target is smaller than the sum, decrease the sum by trading the larger number (end) for a smaller one
     *      If the target is larger than the sum, increase the sum by trading the smaller number (front) for a larger one
     *      If the target == the sum return the indeces 
     *      If the 2 pointers (front and end) meet then no such pair exists
     */
    static std::vector<int> search(const std::vector<int> &arr, int targetSum) {
        int start = 0;
        int end = arr.size()-1;
        std::vector<int> result = {-1, -1};

        while (start < end) {
            int currSum = arr.at(start) + arr.at(end);

            if ( currSum == targetSum ){
                // Found the pair
                result.at(0) = start;
                result.at(1) = end;
                return result;
            }
            
            if ( currSum > targetSum ){
                // Need a pair with a smaller sum
                end--;
            } else {
                // Need a pair with a larger sum
                start++;
            } 
        }

        return result;
    }

};

int main(int argc, char *argv[]) {
    Solution sol;

    std::vector<int> v1 = {1, 2, 3, 4, 6};
    std::vector<int> v2 = {2, 2};
    std::vector<int> v3 = {5, 7, 9, 11};
    std::vector<int> v4 = {10};


    std::vector<int> result = sol.search(v1, 6);
    std::cout << "Pair with target sum: [" << result[0] << ", " << result[1] << "]" << std::endl;

    result = sol.search(v2, 4);
    std::cout << "Pair with target sum: [" << result[0] << ", " << result[1] << "]" << std::endl;

    result = sol.search(v3, 3);
    std::cout << "Pair with target sum: [" << result[0] << ", " << result[1] << "]" << std::endl;

    result = sol.search(v4, 10);
    std::cout << "Pair with target sum: [" << result[0] << ", " << result[1] << "]" << std::endl;
    
}