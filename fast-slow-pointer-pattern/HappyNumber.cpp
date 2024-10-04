#include <iostream>

#include <iostream>

class Solution {
    public:

    /**
     * Happy Number (medium)
     * 
     * Any number will be called a happy number if, 
     * after repeatedly replacing it with a number equal to the sum of the squares of its digits, 
     * leads us to the number 1. 
     * 
     * All other (not-happy) numbers will never reach 1. 
     * Instead, they will be stuck in a cycle of numbers that does not include 1.
     * 
     * Given a positive number n, return true if it is a happy number otherwise return false.
     * 
     * Example 1:
     *      Input: 23
     *      Output: true (23 is a happy number)  
     * Explanations: Here are the steps to find out that 23 is a happy number:
     *      23 => 4 + 9 = 13 
     *      13 => 1 + 9 = 10 
     *      10 => 1 + 0 = 1     Notice that at this point every subsequent step = 1
     * 
     * Logic: 
     *      At each iteration the n = the sum of the squares of n's digits
     *      If the number is a magic number: the process loops on n = 1
     *      If not a magic number: the process will still loop but on n != 1
     * 
     *      The slow pointer moves to the next number generated in the sequence
     *      The fast pointer skips the next number and computes the one after that
     * 
     *      In both cases there is a loop in the sequence so at some point slow == fast
     *      If they both equal 1 then return true. Otherwise return false.
     * 
     * Time Complexity: O(log N)
     * Space Complexity: O(1)
     * 
     */
    bool find(int num) {
        
        int slow = num;
        int fast = squaredDigits(squaredDigits(num));

        while (slow != fast) {
            slow = squaredDigits(slow);
            fast = squaredDigits(squaredDigits(fast));
        }

        if (slow == 1) return true;

        return false;
    }

    int squaredDigits (int num) {

        int squaredDigits = 0;
        while( num > 9) {
            int digit = num % 10;
            squaredDigits += (digit * digit);
            num = (num - digit) / 10;
        }

        return squaredDigits + (num * num);
    }
};

int main(int argc, char* argv[]) {
    Solution sol;
    std::cout << sol.find(23) << std::endl;
    std::cout << sol.find(12) << std::endl;
}