#include <iostream>
#include <vector>

class Solution 
{
    public:

    /**
     * Maximum Sum Subarray of Size K (easy)
     * 
     * Given an array of positive numbers and a positive number 'k,' 
     * find the maximum sum of any contiguous subarray of size 'k'.
     * 
     * Example 1:
     *      Input: arr = [2, 1, 5, 1, 3, 2], k=3 
     *      Output: 9
     *      Explanation: Subarray with maximum sum is [5, 1, 3]
     * 
     * Logic:
     *      Start at idx 0
     *      Sum up the first K elements (idx = 0 to K-1)
     *      Set as maxSum
     *      For each subsequent element:
     *          Add element at idx to sum
     *          Subtract element at idx-k from sum
     *          Compare the new sum with the maxSum
     * 
     * Time Complexity: O(N)
     * Space Complexity: O(1)
     * 
     */

    int findMaxSumSubArray (int k, const std::vector<int>& arr)
    {
        int sum = 0;
        int maxSum = INT_MIN;

        for(int idx = 0; idx < arr.size(); idx++){
            
            sum += arr.at(idx);
            if (idx > k-1)
            {
                sum -= arr.at(idx-k);
            }
            if (idx >= k-1 && sum > maxSum)
            {
                maxSum = sum;
            }
            
        }
        return maxSum;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    std::cout << "Maximum sum of a subarray of size K: "
        << sol.findMaxSumSubArray(3, std::vector<int>{2, 1, 5, 1, 3, 2})
        << std::endl;
    std::cout << "Maximum sum of a subarray of size K: "
        << sol.findMaxSumSubArray(2, std::vector<int>{2, 3, 4, 1, 5})
        << std::endl;
}