#include <iostream>
#include <unordered_map>

class Solution {
    public:
    /**
     * Problem 1: First Non-repeating Character (easy)
     * 
     * Given a string, identify the position of the first character 
     * that appears only once in the string. 
     * 
     * If no such character exists, return -1.
     * 
     * Logic:
     *      given hash map 'm'
     *      for character 'c' in s
     *          if c in m: set m(c) = infinity
     *          else set m(c) = index of c
     * 
     *      iterate through the map and find the key with the lowest value
     *      if lowest value is infinity return -1 else return lowest value
     * 
     * Time Complexity: O(N)
     */
    int firstUniqChar(std::string s) {
        std::unordered_map<char, int> map {};

        for (int idx = 0; idx < s.size(); idx++){
            auto search = map.find(s.at(idx));
            if (search != map.end()){
                // char was already in the map
                search->second = INT_MAX;
            } else {
                // char was not in map
                map[s.at(idx)] = idx;
            }
        }

        int idx = INT_MAX;
        for (auto itr : map){
            if (itr.second < idx) idx = itr.second;
        }

        return (idx < INT_MAX) ? idx : -1;
    }
};