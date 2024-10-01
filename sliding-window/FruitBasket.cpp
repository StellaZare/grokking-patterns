#include <iostream>
#include <unordered_map>
#include <vector>

class Solution
{
    public:
    /**
     * Fruits into Baskets (medium)
     * 
     * You are visiting a farm to collect fruits. The farm has a single row of fruit trees. 
     * You will be given two baskets, and your goal is to pick as many fruits as possible to be placed in the given baskets.
     * You will be given an array of characters where each character represents a fruit tree. 
     * The farm has following restrictions:
     *      Each basket can have only one type of fruit. 
     *      There is no limit to how many fruit a basket can hold.
     *      You can start with any tree, but you can’t skip a tree once you have started.
     *      You will pick exactly one fruit from every tree until you cannot, i.e., you will stop when you have to pick from a third fruit type.
     *      Write a function to return the maximum number of fruits in both baskets.
     * 
     * Example 1:
     *      Input: arr=['A', 'B', 'C', 'A', 'C'] 
     *      Output: 3  
     *      Explanation: We can put 2 'C' in one basket and one 'A' in the other from the subarray ['C', 'A', 'C']
     * 
     * Logic/Think through:
     *      Very similar to the "longest substring with K distinct letters" but K = 2
     *      For each tree in the array
     *      if the tree has been picked: do nothing
     *      if the tree has not been picked: add the tree to the set of picked
     *      if the set of picked trees is greater than 2: 
     *          check the number of picked fruits and compare with the running max
     *          remove the front trees
     */
    int findLength( const std::vector<char> & arr)
    {
        int maxFruit = INT_MIN;
        int start = 0;

        std::unordered_map<char, int> treesPicked {};

        for (int end = 0; end < arr.size(); end++)
        {
            // Pick the current tree
            char currentTree = arr.at(end);
            treesPicked[currentTree]++;

            // While too many trees...
            while (treesPicked.size() > 2)
            {
                // Remove the front fruit
                char removeTree = arr.at(start);
                treesPicked.at(removeTree)--;
                // If last fruit then remove the tree
                if (treesPicked.at(removeTree) == 0) treesPicked.erase(removeTree);
                // Slide the window
                start++;
            }

            maxFruit = std::max(maxFruit, end-start+1);
        }

        if (maxFruit == INT_MIN) return arr.size();
        
        return maxFruit;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    std::vector<char> v1 = {'A', 'B', 'C', 'A', 'C'};
    std::vector<char> v2 = {'A', 'B', 'C', 'B', 'B', 'C'};
    std::vector<char> v3 = {'A', 'B', 'A', 'B', 'B', 'C'};

    std::cout << "Maximum number of fruits: " << sol.findLength(v1) << std::endl;
    std::cout << "Maximum number of fruits: " << sol.findLength(v2) << std::endl;
    std::cout << "Maximum number of fruits: " << sol.findLength(v3) << std::endl;
}