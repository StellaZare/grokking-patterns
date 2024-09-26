#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Solution
{
public:
    /**
     * Triplet Sum Close to Target (medium)
     *
     * Given an array of unsorted numbers and a target number,
     * find a triplet in the array whose sum is as close to the target number as possible,
     * return the sum of the triplet.
     *
     * If there are more than one such triplet, return the sum of the triplet with the smallest sum.
     *
     * Logic:
     *      how to compare the closeness of the s1 and s2 with the target?
     *      abs (target - s1) < abs (target - s2)
     *      suppose target = 5 and s1 = 3 and s2 = 6
     *      abs(5-3) < abs(5-6) => 2 < 1
     *      => if abs (target - s1) < abs (target - s2) then s1 is closer
     *      => else if abs (target - s1) == abs (target - s2) then choose min (s1, s2)
     *      => choose s2
     * 
     * Time Compleity: 
     *      O(N * log N)    to sort
     *      O(N^2)          to find triplets
     */
    int searchTriplet(std::vector<int> &arr, int targetSum)
    {
        sort(arr.begin(), arr.end());

        int savedSum = INT_MAX;

        for (int idx = 0; idx < arr.size(); idx++)
        {
            int front = idx + 1;
            int back = arr.size() - 1;

            while (front < back)
            {
                int currentSum = arr.at(idx) + arr.at(front) + arr.at(back);

                // Is the current sum closer than the saved sum?
                if (abs(targetSum - currentSum) < abs(targetSum - savedSum))
                {
                    // The current sum is closer to the target => replace savedSum
                    savedSum = currentSum;
                }
                else if (abs(targetSum - currentSum) == abs(targetSum - savedSum))
                {
                    // The current and saved are the same distance apart => choose min
                    savedSum = std::min(savedSum, currentSum);
                }

                if (currentSum == targetSum)
                    return currentSum;
                else if (currentSum < targetSum)
                    front++;
                else
                    back--;
            }
        }
        return savedSum;
    }
};

int main()
{
    std::vector<int> v1 = {-1, 0, 2, 3};
    std::vector<int> v2 = {-3, -1, 1, 2};
    std::vector<int> v3 = {1, 0, 1, 1};

    Solution sol;

    std::cout << sol.searchTriplet(v1, 3) << std::endl;
    std::cout << sol.searchTriplet(v2, 1) << std::endl;
    std::cout << sol.searchTriplet(v3, 100) << std::endl;

    return 0;
}