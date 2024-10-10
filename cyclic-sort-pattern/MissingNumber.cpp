#include <iostream>
#include <vector>

class Solution {
    public:
    /**
     * Find the Missing Number (easy)
     * 
     * We are given an array containing n distinct numbers taken from the range 0 to n. 
     * Since the array has only n numbers out of the total n+1 numbers, find the missing number.
     * 
     * Example 1:
     *      Input: [4, 0, 3, 1]
     *      Output: 2
     * 
     * Probably not the intended solution but...
     *      The sum of numbers 0 to n: S_n = 0 + 1 + 2 + ... + n
     *      But one of the numbers is missing
     *      So summing the elements in the array we get S_array = S_n - x
     *      Where x is the missing number
     * 
     * Time Complexity: O(N)
     * Space Complexity: O(1)
     * 
     */
    static int findMissingNumber2(std::vector<int> &nums) {
        
        int sum = 0;

        for (int idx = 0; idx < nums.size(); idx++) {
            sum += idx;
            sum -= nums.at(idx);
        }
        
        return sum + nums.size();
    }

    /**
     * For each element e
     * If e < nums.size() and e not in the right place: 
     *      Put e at index e and put the element at index e at the current index
     * Else move on to the next element
     * 
     * After this loop all numbers 0 to n-1 should be in the correct spot
     * Iterate through the list and if you spot a number not in the correct spot return the idx
     * If no not found then return n 
     */
    static int findMissingNumber(std::vector<int> &nums) {
        int idx = 0;
        while (idx < nums.size()){
            if (idx == nums.at(idx) || nums.at(idx) == nums.size()) idx++;
            else {
                int e = nums.at(idx);
                int s = nums.at(e);
                nums.at(e) = e;
                nums.at(idx) = s; 
            }
        }
    
        for (idx = 0; idx < nums.size(); idx++) {
            if (idx != nums.at(idx)) return idx;
        }

        return nums.size();
    }

};

int main(int argc, char *argv[]) {
    Solution sol;
    std::vector<int> v1 = {4, 0, 3, 1};
    std::cout << sol.findMissingNumber(v1) << std::endl;
    v1 = {8, 3, 5, 2, 4, 6, 0, 1};
    std::cout << sol.findMissingNumber(v1) << std::endl;
}