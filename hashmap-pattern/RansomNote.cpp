#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
    public:
    /**
     * Problem 5: Ransom Note (easy)
     * 
     * Given two strings, one representing a ransom note and the other 
     * representing the available letters from a magazine, determine if it's 
     * possible to construct the ransom note using only the letters from the magazine. 
     * Each letter from the magazine can be used only once.
     */
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::unordered_map<char, int> letters {};

        for (auto& c : magazine){
            letters[c]++;
        }

        for (auto& c : ransomNote){
            letters[c]--;
            if (letters[c] < 0) 
                return false;
        }
        return true;
    }
};