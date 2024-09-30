#include <iostream>
#include <string>
#include <unordered_map>

class Solution 
{
    public:
    /**
     * Longest Substring with K Distinct Characters (medium)
     * 
     * Given a string, find the length of the longest substring in it 
     * with no more than K distinct characters.
     * 
     * You can assume that K is less than or equal to the length of the given string.
     * 
     * Example 1:
     *      Input: String="araaci", K=2  
     *      Output: 4  
     *      Explanation: The longest substring with no more than '2' distinct characters is "araa".
     * 
     * Logic:
     *      use a map to keep track of the 'seen' character
     *      Start and end interval at idx 0
     *      If character in map then seen. 
     *          Increment back and look at the next character.
     *      Else unseen and distinct count incements.
     *          If distinct count > K
     *          Check if length is longest seen yet
     *          Remove the letter at front from the map and increment front until you reach the next letter.
     * 
     * Time Complexity: O(N)
     * Space Complexity: O(1)
     */
    int findLength(const std::string& str, int k)
    {
        std::unordered_map<char, int> seenCharacters {};

        int front = 0; 
        int back = 0;
        int maxLength = INT_MIN;
        int numDistinct = 0;

        while (back < str.size())
        {
            // character not in substring -> increment num distinct
            if (seenCharacters.find(str.at(back)) == seenCharacters.end())
            {   
                numDistinct++;
            }

            if (numDistinct > k)
            {
                // calculate the current subtring length
                int length = back - front + 1;
                if (length > maxLength) maxLength = length;

                // slide the window eliminating the front character
                char currentFront = str.at(front);
                while (front < str.size() && str.at(front) == currentFront)
                {
                    front++;
                }

                // remove front character from seen chars
                seenCharacters.erase(currentFront);
                numDistinct--;
            }
            back++;
        }
        return maxLength;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    std::cout << "Length of the longest substring: "
        << sol.findLength("araaci", 2) << std::endl;
    std::cout << "Length of the longest substring: "
        << sol.findLength("araaci", 1) << std::endl;
    std::cout << "Length of the longest substring: "
        << sol.findLength("cbbebi", 3) << std::endl;
}