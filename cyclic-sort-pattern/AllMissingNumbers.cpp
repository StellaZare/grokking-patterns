#include <iostream>
#include <vector>

class Solution {
    public:
    /**
     * Find all Missing Numbers (easy)
     * 
     * We are given an unsorted array containing numbers taken from the range 1 to ‘n’. 
     * The array can have duplicates, which means some numbers will be missing. 
     * Find all those missing numbers.
     * 
     * Example 1:
     *      Input: [2, 3, 1, 8, 2, 3, 5, 1]
     *      Output: 4, 6, 7
     * 
     * Explanation: The array should have all numbers from 1 to 8, due to duplicates 4, 6, and 7 are missing.
     * 
     * Logic:
     *      Use the same approach to finding one missing number
     * 
     * Twist 1: if the number is a duplicate youll get stuck in inf loop
     *      modify increment condition to say: if the number im looking at has already been placed once then move on
     *      so if nums.at(idx) has been placed in its index i = nums.at(idx)-1 then move on
     *      so if nums.at(i) == nums.at(idx) then move on
     *      
     * Twist 2: if an index i holds an incorrect number n -> n != i+1 
     *      then the value at index i was missing
     * 
     * Note:  element x is at index x-1
     *        index i holds element i+1
     * 
     * Time Complexity: O(N+N) = O(N)
     * Space Complexity: O(N) for the list of missing elements
     */
    std::vector<int> findNumbers(std::vector<int> &nums) {
        std::vector<int> missingNumbers;

        int idx = 0;
        while (idx < nums.size()){
            int e = nums.at(idx);

            if (nums.at(e-1) == e) idx++;
            else {
                int s = nums.at(e-1);

                nums.at(idx) = s;
                nums.at(e-1) = e;
            }
        }

        for(idx = 0; idx < nums.size(); idx++){
            int value = idx+1;
            if (nums.at(idx) != value) missingNumbers.push_back(value);
        }
        
        return missingNumbers;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    std::vector<int> v1 = {2, 3, 1, 8, 2, 3, 5, 1};
    std::vector<int> missing = sol.findNumbers(v1);
    std::cout << "Missing numbers: ";
    for (auto num : missing) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    v1 = {2, 4, 1, 2};
    missing = sol.findNumbers(v1);
    std::cout << "Missing numbers: ";
    for (auto num : missing) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    v1 = {2, 3, 2, 1};
    missing = sol.findNumbers(v1);
    std::cout << "Missing numbers: ";
    for (auto num : missing) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}