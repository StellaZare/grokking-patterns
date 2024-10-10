#include <iostream>
#include <vector>

class Solution {
    public:
    /**
     * Cyclic Sort (easy)
     * 
     *  Write a function to sort the objects in-place on their creation sequence number in  without using any extra space. 
     *  Return the sorted list.
     * 
     * Example 1:
     *     Input: [3, 1, 5, 4, 2]
     *    Output: [1, 2, 3, 4, 5]
     * 
     * 
     */
    std::vector<int> sort(std::vector<int> &nums) {
        
        int idx = 0;

        while ( idx < nums.size() ) {
            if (nums.at(idx) == idx+1) {
                // elemnent in the correct index
                idx++;
            } else {
                // swap elements at current index and current elements index
                int curr = nums.at(idx);
                int swap = nums.at(curr-1);

                nums.at(curr-1) = curr;
                nums.at(idx) = swap;
            }
        }
        return nums;
    }
};


int main(int argc, char *argv[]) {
    Solution sol;
    std::vector<int> arr = {1, 5, 6, 4, 3, 2};
    arr = sol.sort(arr);
    for (auto num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    arr = {6, 5, 4, 3, 2, 1};
    arr = sol.sort(arr);
    for (auto num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    arr = {1, 6, 2, 5, 3, 4};
    arr = sol.sort(arr);
    for (auto num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    arr = {1, 5, 4, 3, 2};
    arr = sol.sort(arr);
    for (auto num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
