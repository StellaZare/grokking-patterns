#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
    public:
    /**
     * Find all Duplicate Numbers (easy)
     * 
     * We are given an unsorted array containing n numbers taken from the range 1 to n. 
     * The array has some numbers appearing twice, find all these duplicate numbers using constant space.
     * 
     * Example 1:
     *      Input: [3, 4, 4, 5, 5]
     *      Output: [4, 5]
     * 
     * Logic:
     *      element e is at index e-1  -> index i has element i+1
     *      element e is in the 'right spot' if nums.at(e-1) == e
     * 
     *      for index i in list:
     *          let e = element at i
     *          if (e == element at e-1) then element in the right spot already move on to next i
     *          else 
     *              swap the element e in current index with the element in e's spot
     *              let s = element at e-1
     *              nums.at(e-1) = e
     *              nums.at(i) = s
     *        
     *      All elements present should be in their 'spots'
     *      look for duplicates
     *      for index i in list:
     *          let e = element at i
     *          if e != i+1 
     *              the element at this index = [i+1] was not found
     *              the elent currently in index i is a duplicate
     */
    std::vector<int> findNumbers(std::vector<int> &nums) { 
        std::vector<int> duplicateNumbers;

        int i = 0;
        while (i < nums.size()){
            int e = nums.at(i);
            if (nums.at(e-1) == e) i++;
            else {
                int s = nums.at(e-1);
                nums.at(e-1) = e;
                nums.at(i) = s;
            }
        }

        for (i = 0; i < nums.size(); i++){
            if (nums.at(i) != i+1){
                duplicateNumbers.push_back(nums.at(i));
            }
        }

        return duplicateNumbers;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    std::vector<int> v1 = {3, 4, 4, 5, 5};
    std::vector<int> duplicates = sol.findNumbers(v1);
    std::cout << "Duplicates are: ";
    for (auto num : duplicates) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    v1 = {5, 4, 7, 2, 3, 5, 3};
    duplicates = sol.findNumbers(v1);
    std::cout << "Duplicates are: ";
    for (auto num : duplicates) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}