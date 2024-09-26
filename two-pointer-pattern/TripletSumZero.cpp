#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
    /**
     * Triplet Sum to Zero (medium)
     *
     * Given an array of unsorted numbers, find all triplets in it that add up to zero.
     * Example 1:
     *      Input: [-3, 0, 1, 2, -1, 1, -2]
     *      Output: [[-3, 1, 2], [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]]
     *
     * Logic:
     *      Starting at the first number 'n' find all pairs (a, b) in the remaining list s.t. a + b = -n
     *      Add each pair to the list of triplets as (n, a, b)
     *      Once complete you have found all triples with 'n' as an element so move on to the next value
     *      Everytime you move on you need check for pairs in a smaller set (the remaining unchecked list)
     *
     * Time Complexity: O(N^2)
     *      O(N * log N)    sorting the array
     *      O(N * N)        searching for triplets
     *
     * Space Complexity: O(N)
     *
     */
    static std::vector<std::vector<int>> searchTriplets(std::vector<int> &arr)
    {

        std::vector<std::vector<int>> triplets = {};
        sort(arr.begin(), arr.end());

        for (int idx = 0; idx < arr.size(); idx++)
        {
            int n = arr.at(idx);

            // Set the front and back of the 'unchecked' subset
            int frontIdx = idx + 1;
            int backIdx = arr.size() - 1;

            while (frontIdx < backIdx)
            {
                int a = arr.at(frontIdx);
                int b = arr.at(backIdx);

                if (a + b == -n)
                {
                    // Found triplet to add
                    triplets.push_back({n, a, b});
                    frontIdx++;
                    backIdx--;

                    std::cout << "[" << n << ", " << a << ", " << b << "]" << std::endl;

                    // Skip duplicates in the set
                    while (frontIdx < backIdx && arr.at(frontIdx) == arr.at(frontIdx - 1))
                        frontIdx++;
                    while (frontIdx < backIdx && arr.at(backIdx) == arr.at(backIdx + 1))
                        backIdx++;
                }
                else if (a + b > -n)
                {
                    backIdx--;
                }
                else if (a + b < -n)
                {
                    frontIdx++;
                }
            }
        }
        return triplets;
    }
};

int main()
{
    Solution sol;

    std::vector<int> v1 = {-1, 0, 1, 2, -1, -4};
    sol.searchTriplets(v1);

    return 0;
}