#include <string>
#include <stack>
#include <iostream>

class Solution {
    public:
    /**
     * Remove All Adjacent Duplicates In String (easy)
     * 
     * You are given a string s consisting of lowercase English letters. 
     * A duplicate removal consists of choosing two adjacent and equal letters and removing them.
     * We repeatedly make duplicate removals on s until we no longer can.
     * 
     * Example: 
     *      Input: "abccba"
     *      Output: ""
     * 
     * Logic:
     *      given stack 'sk' and string 's'
     *      for char 'c' in s:
     *          if top of sk == 'c' pop the top
     *          else push 'c'
     * 
     *      create a string 'r' st. r.size() == sk.size()
     *      pop elements from the stack and place in 'r' end to start
     */
    std::string removeDuplicates(std::string s) {
        std::stack<char> sk;

        for(char& c : s){
            if (!sk.empty() && sk.top() == c) sk.pop();
            else sk.push(c);
        }

        int str_length = sk.size();
        std::string result;
        result.resize(str_length);

        for(int idx = str_length-1; idx >= 0; idx--){
            result.at(idx) = sk.top();
            sk.pop();
        }

        return result;
    }
};

int main() {
    Solution solution;
    std::cout << solution.removeDuplicates("abccba") << std::endl; // Output: ""
    std::cout << solution.removeDuplicates("foobar") << std::endl; // Output: "fbar"
    std::cout << solution.removeDuplicates("abcd") << std::endl; // Output: "abcd"
    return 0;
}