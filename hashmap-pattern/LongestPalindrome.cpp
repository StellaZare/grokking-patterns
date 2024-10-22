#include <iostream>
#include <unordered_map>

class Solution {
    public:
    /**
     * Problem 4: Longest Palindrome(easy)
     * 
     * Given a string, determine the length of the longest palindrome that can be constructed using the characters from the string. 
     * You don't need to return the palindrome itself, just its maximum possible length.
     * 
     * Logic:
     *      A palindrome is a string that is the same read forwards and backwards
     *      For character 'c' in the string count the number of occurances.
     * 
     *      iterate through the (character, count) pairs
     *      if a character appears an even number of times: max_length += count
     *      if a character appears an odd number of times: max_length += count-1
     *      if there existed any odd occurances then max_length++
     * 
     *      return max_length
     * 
     * Time Complexity: O(N)
     */
    int longestPalindrome(std::string s) {        

        std::unordered_map<char, int> character_occurance {};
        for (auto& c : s) {
            character_occurance[c]++;
        }

        int length = 0;
        bool had_odd = false;
        bool had_even = false;
        for (auto itr : character_occurance){
            if (itr.second % 2 == 0){
                // even occurances
                length += itr.second;
                had_even = true;
            } else {
                length += (itr.second - 1);
                had_odd = true;
            }
        }

        // ToDo: Write Your Code Here.
        return (had_odd) ? length+1 : length;
    }
};  