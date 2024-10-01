#include <iostream>
#include <vector>

class Solution {

/**
 * Find the average for all subarrays of size K in the given array
 * 
 * Logic:
 *      for the first K-1 elements add up the elements (if K = 3 => indeces 0 and 1)
 *      at or after the first K elements add the current idx, subtract the value at idx
 * 
 * Example:
 *      K = 3: 1, 3, 2, 6, -1
 */
public:
    std::vector<double> findAverages(int K, const std::vector<int> &arr)
    {
        double sum = 0;
        std::vector<double> averages {};

        for (int idx = 0; idx < arr.size(); idx++)
        {
            sum += arr.at(idx);

            if (idx == K-1)
            {
                // Seen the first K elements -> take the average
                averages.push_back(sum/K);
            }
            else if (idx > K-1)
            {
                // Move the window then take the average
                sum -= arr.at(idx-K);
                averages.push_back(sum/K);
            }
        }
        return averages;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    std::vector<double> result = sol.findAverages(5, std::vector<int> {1, 3, 2, 6, -1, 4, 1, 8, 2});
    std::cout << "Averages of subarrays of size K: ";
    for (double d : result)
    {
        std::cout << d << " ";
    }
    std::cout << std::endl;
}
