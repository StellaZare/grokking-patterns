using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class Solution {
    private:
    /**
     * smallerHalf orders the values smaller than the median
     * biggerHalf orders the values larger or equal to the median
     */
    std::priority_queue<int> smallerHalf {};
    std::priority_queue<int, std::vector<int>, greater<int>> biggerHalf {};

    public:
    /**
     * Find the Median of a Number Stream (medium)
     * 
     * Design a class to calculate the median of a number stream. 
     * The class should have the following two methods:
     *      insertNum(int num): stores the number in the class
     *      findMedian(): returns the median of all numbers inserted in the class
     * 
     * If the count of numbers inserted in the class is even, the median will be the average of the middle two numbers.
     */
    Solution() {
        // TODO: Write your code here


    }

    /**
     * if it the first number 
     * or the number is smaller than or equal to the largest number in the smaller half
     *      the number belongs in the smaller half
     * else the number belongs in the larger half
     * 
     * if the smaller half has 2 more elements than the larger: move one from small to large
     * if the larger half has 1 more element than the smaller: move one from large to small
     * 
     */
    void insertNum(int num) {
        if (smallerHalf.empty() || smallerHalf.top() >= num) 
            smallerHalf.push(num);
        else    
            biggerHalf.push(num);

        if (smallerHalf.size() > biggerHalf.size() + 1){
            biggerHalf.push(smallerHalf.top());
            smallerHalf.pop();
        } else if (biggerHalf.size() > smallerHalf.size()){
            smallerHalf.push(biggerHalf.top());
            biggerHalf.pop();
        }
    }

    double findMedian() {
        if (smallerHalf.empty()) return 0;
        if (smallerHalf.size() == biggerHalf.size()) return (smallerHalf.top()/2.0 + biggerHalf.top()/2.0);

        return smallerHalf.top();
    }

};