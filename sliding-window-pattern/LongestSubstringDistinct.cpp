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
     *      For each letter:
     *          Consume the letter at the back ptr & incrment the count in the map
     *          While over the threshold:
     *              Remove the letter at the front from map and increment the front ptr
     *              If removing the last occurance of the letter then erase the letter
     *          Update max length if needed
     * 
     * Time Complexity: O(N)
     * Space Complexity: O(1)
     */
    int findLength(const std::string& str, int k)
    {
        std::unordered_map<char, int> seenCharacters {};

        int frontPtr = 0; 
        int maxLength = INT_MIN;

        for (int backPtr = 0; backPtr < str.size(); backPtr++)
        {
            // Add the current char to the seen characters
            char current = str.at(backPtr);
            seenCharacters[current]++;

            // Check if seen more characters than permitted
            while (seenCharacters.size() > k)
            {
                // Forget the front character
                char forget = str.at(frontPtr++);
                seenCharacters.at(forget)--;
                if (seenCharacters.at(forget) == 0) seenCharacters.erase(forget);
            }

            int currentLength = backPtr - frontPtr + 1;
            maxLength = std::max (maxLength, currentLength);
        }

        if (maxLength == INT_MIN) return str.size();
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
        << sol.findLength("aabacbebebe", 3) << std::endl;
}