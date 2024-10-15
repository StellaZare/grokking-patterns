#include <iostream>
#include <stack>

class Solution {
    public:
    /**
     * Balanced Parentheses
     * 
     * Given a string s containing () [] {} characters. 
     * Determine if a given string of parentheses is balanced.
     * A string of parentheses is considered balanced if every opening parenthesis has a corresponding closing parenthesis in the correct order.
     * 
     * Examples:
     *      s = "{[()]}"    TRUE
     *      s = "{[}]"      FALSE
     * 
     * Logic:
     *      Iterate through the string one character 'c' at a time
     *      if 'c' is an opening parenthesis i.e. ([{ then: push 'c' on the stack
     *      else (when 'c' is a closing parenthesis)
     *          let 't' be the character at the top of the stack
     *          if t is paired with c ie. t = '[' c = ']' or t = '{' c = '}' or ...
     *              pop t from the stack and continue
     *          else (when t is not the pair or stack empty)
     *              return false
     * 
     *      After iterating through all the chars in the string
     *      if stack is empty return true
     *      else return false
     * 
     * Time Complexity: O(N)
     * Space Complexity: O(N) for the stack
     */
    bool isValid(std::string s){
        std::stack<char> stack;

        for(auto& c : s){
            // If opening add to stack
            if (c == '[' || c == '{' || c == '(') stack.push(c);
            else {
                // Empty stack
                if (stack.empty()) return false;

                // Look for match
                auto t = stack.top();
                if ((t == '[' && c == ']') || (t == '{' && c == '}') || (t == '(' && c == ')')){
                    stack.pop();
                    continue;
                } else return false;
            }
        }

        return stack.empty();
    }
};

int main() {
    Solution sol;

    std::string test1 = "{[()]}"; // Should be valid
    std::string test2 = "{[}]";   // Should be invalid
    std::string test3 = "(]";     // Should be invalid
    
    std::cout << "Test 1: " << sol.isValid(test1) << std::endl;
    std::cout << "Test 2: " << sol.isValid(test2) << std::endl;
    std::cout << "Test 3: " << sol.isValid(test3) << std::endl;

    return 0;
}