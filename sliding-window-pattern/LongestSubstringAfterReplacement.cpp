#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
    /**
     * Longest Substring with Same Letters after Replacement (hard)
     * 
     * Given a string with lowercase letters only, 
     * if you are allowed to replace no more than ‘k’ letters with any letter, 
     * find the length of the longest substring having the same letters after replacement.
     * 
     * Example 1:
     *      Input: str="aabccbb", k=2  
     *      Output: 5
     * 
     * Thinking:
     *      Similar to the "longest substring with at most K distinct letters"
     *      Difference is now its not the number of distict letters but rather occurances of unknown letters
     *      
     *      Use map Mseen to keep track of the letters you have seen
     *      Use map Mrep to keep track of the letter you have 'replaced'
     *      for each letter in string
     *      add the letter to the Mseen if already in map increment its value
     *      if (Mseen.size() > 1)  add the letter to Mrep
     *      if (Mseen.size() > 1 and Mrep.size() > K) {
     *          remove front letter from seen
     *          if (last one erasing the letter) remove a letter from rep
     *      }
     *         
     *      
     */
    public:
    int findLength(const std::string &str, int k)
    {
      int maxLength = 0;
      // TODO: Write your code here
      return maxLength;
    }
};