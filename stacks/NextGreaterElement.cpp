#include <iostream>
#include <stack>

#include <vector>

class Solution {
    public:
    /**
     * Next Greater Element
     * 
     * Given an array, print the Next Greater Element (NGE) for every element.
     * The Next Greater Element for an element x is the first greater element on the right side of x in the array.
     * 
     * Elements for which no greater element exist, consider the next greater element as -1.
     * 
     * Logic:
     *      for element 'e' in array
     *          while 'e' is greater than the top of stack
     *              add 'e' to the resulting list
     *              pop the top of the stack
     *          push 'e' onto the stack
     * 
     *              
     */
    std::vector<int> nextLargerElement(std::vector<int> arr) {
        int n = arr.size();
        std::vector<int> res {};
        res.resize(n);

        std::stack<int> stack {};
    
        for(int idx = n-1; idx >= 0; idx--){

            while(!stack.empty() && stack.top() <= arr.at(idx)){
                stack.pop();
            }

            if (stack.empty()) res.at(idx) = -1;
            else res.at(idx) = stack.top();

            stack.push(arr.at(idx));
        }

        return res;
    }
};

int main() {
    std::vector<int> arr = { 11, 13, 21, 3 };
    std::vector<int> arr2 = { 4, 5, 2, 25 };
    std::vector<int> arr3 = { 13, 7, 6, 12 };
    Solution nge;
    
    // Calculate and print the NGE for each element in the first input array.
    std::vector<int> res1 = nge.nextLargerElement(arr);
    for(auto& i : res1)
        std::cout << i << " ";
    std::cout << std::endl;
    
    // Calculate and print the NGE for each element in the second input array.
    std::vector<int> res2 = nge.nextLargerElement(arr2);
    for(auto& i : res2)
        std::cout << i << " ";
    std::cout << std::endl;
    
    // Calculate and print the NGE for each element in the third input array.
    std::vector<int> res3 = nge.nextLargerElement(arr3);
    for(auto& i : res3)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}