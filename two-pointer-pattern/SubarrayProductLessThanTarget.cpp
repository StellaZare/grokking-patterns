#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Solution
{
public:
    /**
     * Subarrays with Product Less than a Target (medium)
     *
     * Given an array with positive numbers and a positive target number,
     * find all of its contiguous subarrays whose product is less than the target number.
     *
     * Example 1:
     *      Input: [2, 5, 3, 10], target=30
     *      Output: [2], [5], [2, 5], [3], [5, 3], [10]
     *
     * Explanation:
     *      There are six contiguous subarrays whose product is less than the target.
     *
     * Logic:
     *      start with L and R ptr at idx zero
     *      while the sub array is increasing (R <= R+1) increment R
     *          if R is less than target -> sub array of length one
     *          keep track of the running product (L * ... * R) 
     *      if the running product is < target: add [L, ..., R]
     *      if the running product is > target: do nothing
     *      increment L
     *      if L == R increment R
     *
     * Time Complexity:
     *      O(N)    sliding window
     *      O(N^2)  creating subarrays in the worst case 
     *      => O(N^3)
     *
     * 
     */
    std::vector<std::vector<int>> findSubarrays(std::vector<int> &arr, int target)
    {
        std::vector<std::vector<int>> subarr {};

        int left = 0;
        int right = 0;
        int product = 1;

        for (right = 0; right < arr.size(); right++)
        {
            product *= arr.at(right);

            while (product >= target && left < arr.size())
            {
                product /= arr.at(left++);
            }

            if (left != right)
            {
                subarr.push_back({arr.at(right)});
            }

            subarr.push_back(getSubarray(arr, left, right));
        }

        return subarr;
    }

    std::vector<int> getSubarray(std::vector<int>& arr, int start, int end)
    {
        std::vector<int> subarray {};
        for(int idx = start; idx <= end && idx < arr.size(); idx++ )
        {
            subarray.push_back(arr.at(idx));
        }
        return subarray;
    }
};

int main()
{
    Solution sol;

    std::vector<int> v1 = {2, 5, 3, 10};

    for (std::vector<int>& v : sol.findSubarrays(v1, 30)){
        std::cout << "[";
        
        for(int& x : v)
        {
            std::cout << " " << x << " ";
        }
        
        std::cout << "], ";
    }
}