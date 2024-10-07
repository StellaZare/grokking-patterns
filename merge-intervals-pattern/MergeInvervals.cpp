#include <algorithm>
#include <iostream>
#include <vector>

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
     * Merge Intervals (medium)
     * 
     * Given a list of intervals, merge all the overlapping intervals to produce a 
     * list that has only mutually exclusive intervals.
     * 
     * Example 1:
     *      Intervals: [[1,4], [2,5], [7,9]]
     *      Output: [[1,5], [7,9]]
     * 
     * Explanation: Since the first two intervals [1,4] and [2,5] overlap, we merged them into one [1,5].
     * 
     * Logic: the 6 scenarios
     *      a.end < b.start     no overlap
     *      b.end < a.start     no overlap
     *      a.start < b.start && b.end < a.end      b covered by a
     *      b.start < a.start && a.end < b.end      a covered by b
     *      a.start < b.start && a.end < b.end      new interval [a.start, b.end]
     *      b.start < a.start && b.end < a.end      new interval [b.start, a.end]
     */
    std::vector<Interval> merge(std::vector<Interval> &intervals) {
        std::vector<Interval> mergedIntervals;

        if (intervals.size() < 2) return intervals;

        // Sort inervals by start time
        sort( intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) { return a.start < b.start; } );

        // Interval to add or expand
        Interval currentInterval = intervals.at(0);

        for (int compIdx = 0; compIdx < intervals.size(); compIdx++) {
            Interval& compare = intervals.at(compIdx);

            // after sort currentInterval.start <= compare.start
            if (compare.start <= currentInterval.end && currentInterval.end < compare.end) {
                // intervals overlap
                currentInterval.end = compare.end;
            } else if (compare.start <= currentInterval.end && compare.end <= currentInterval.end) {
                // current interval "covers" the compare interval - do nothing
            } else {
                // no overlap
                mergedIntervals.push_back(currentInterval);
                currentInterval = compare;
            }
        }
        
        mergedIntervals.push_back(currentInterval);
        return mergedIntervals;
    }

};

int main(int argc, char *argv[]) {
    Solution sol;
    std::vector<Interval> input = {{1, 3}, {2, 5}, {7, 9}};
    std::cout << "Merged intervals: ";
    for (auto interval : sol.merge(input)) {
        std::cout << "[" << interval.start << "," << interval.end << "] ";
    }
    std::cout << std::endl;

    input = {{6, 7}, {2, 4}, {5, 9}};
    std::cout << "Merged intervals: ";
    for (auto interval : sol.merge(input)) {
        std::cout << "[" << interval.start << "," << interval.end << "] ";
    }
    std::cout << std::endl;

    input = {{1, 4}, {2, 6}, {3, 5}};
    std::cout << "Merged intervals: ";
    for (auto interval : sol.merge(input)) {
        std::cout << "[" << interval.start << "," << interval.end << "] ";
    }
    std::cout << std::endl;
}