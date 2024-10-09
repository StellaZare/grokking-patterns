#include <iostream>
#include <vector>
#include <algorithm>

class Interval {
    public:
    int start = 0;
    int end = 0;

    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
    public:
    /**
     * Insert Interval (medium)
     * 
     * Given a list of non-overlapping intervals sorted by their start time, 
     * insert a given interval at the correct position and 
     * merge all necessary intervals to produce a list that has only mutually exclusive intervals.
     * 
     * Example 1:
     *      Input: Intervals=[[1,3], [5,7], [8,12]], New Interval=[4,6]
     *      Output: [[1,3], [4,7], [8,12]]
     * 
     * Explanation: After insertion, since [4,6] overlaps with [5,7], we merged them into one [4,7].
     * 
     * Logic:
     *      The input list of intervals is non-overlapping and sorted by start time
     *      Iterate throught the intervals: 
     *          let [] be the current interval and {} the new interval to add
     *          let interted be a flag set to false
     *      if (inserted) add current and continue
     *      else:
     *      case 1:     []{} then add the curr interval to merged list
     *      case 2a:    [{}] then add the curr interval to merged list set inserted
     *      case 2b:    {[]} then add new interval and set inserted
     *      case 3:     [{]} then new = {min(curr.start, new.start), max(curr.end, new.end)}
     *      case 4:     {[}] then new = {min(curr.start, new.start), max(curr.end, new.end)}
     *      case 5:     {}[] then add new interval and set interted *** PLACE ABOVE
     * 
     * Time Complexity: O(N) the number of intervals in the list
     * Space Complexity: O(1) for the algorithm but O(N) for the new merged list
     * 
     */
    std::vector<Interval> insert(const std::vector<Interval> &intervals, Interval newInterval) {
        std::vector<Interval> mergedIntervals;

        bool inserted = false;
        for (int idx = 0; idx < intervals.size(); idx++) {
            const Interval& currInterval = intervals.at(idx);

            if (inserted) {
                mergedIntervals.push_back(currInterval);
                continue;
            }
            
            if (currInterval.end < newInterval.start) {
                mergedIntervals.push_back(currInterval);

            } 
            else if (newInterval.end < currInterval.start) {
                mergedIntervals.push_back(newInterval);
                mergedIntervals.push_back(currInterval);
                inserted = true;

            }
            else if (currInterval.start <= newInterval.start && newInterval.end <= currInterval.end ) {
                mergedIntervals.push_back(currInterval);
                inserted = true;

            }
            else if ( (currInterval.start <= newInterval.start && currInterval.end <= newInterval.end) 
                ||  ( newInterval.start < currInterval.start && newInterval.end < currInterval.end ) 
                ||  ( newInterval.start < currInterval.start && currInterval.end < newInterval.end )) {

                newInterval.start = std::min(currInterval.start, newInterval.start);
                newInterval.end = std::max(currInterval.end, newInterval.end);

            }
        }

        if (!inserted) mergedIntervals.push_back(newInterval);
        
        return mergedIntervals;
    }
};


int main(int argc, char *argv[]) {
    Solution sol;
    std::vector<Interval> input = {{1, 3}, {5, 7}, {8, 12}};
    std::cout << "Intervals after inserting the new interval: ";
    for (auto interval : sol.insert(input, {4, 6})) {
        std::cout << "[" << interval.start << "," << interval.end << "] ";
    }
    std::cout << std::endl;

    std::cout << "Intervals after inserting the new interval: ";
    for (auto interval : sol.insert(input, {4, 10})) {
        std::cout << "[" << interval.start << "," << interval.end << "] ";
    }
    std::cout << std::endl;

    input = {{2, 3}, {5, 7}};
    std::cout << "Intervals after inserting the new interval: ";
    for (auto interval : sol.insert(input, {1, 4})) {
        std::cout << "[" << interval.start << "," << interval.end << "] ";
    }
    std::cout << std::endl;
}