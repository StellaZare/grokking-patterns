#include <algorithm>
#include <iostream>
#include <vector>

class Interval {
    public:
    int start;
    int end;

    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
    public:
    /**
     * Conflicting Appointments (medium)
     * 
     * Given an array of intervals representing ‘N’ appointments, 
     * find out if a person can attend all the appointments.
     * 
     * Example 1:
     *      Appointments: [[1,4], [2,5], [7,9]]
     *      Output: false
     * 
     * Explanation: Since [1,4] and [2,5] overlap, a person cannot attend both of these appointments.
     * 
     * Logic:
     *      if only 1 interval then return true
     *      first sort the list of intervals by their start time
     *      then check that for each interval (a,b) from idx 1 to the end and the prev interval (a', b'): if a <= b' return false
     */
    bool canAttendAllAppointments(std::vector<Interval>& intervals) {
        // list of 0 or 1 trivially no overlap
        if (intervals.size() < 2) return true;

        // sort intervals by start time
        sort(intervals.begin(), intervals.end(), [](const Interval& x, const Interval& y) { 
            return x.start < y.start; 
        });

        // check the list
        for (int idx = 1; idx < intervals.size(); idx++){
            const Interval& curr = intervals.at(idx);
            const Interval& prev = intervals.at(idx-1);
            if (curr.start < prev.end) return false;
        }

        return true;
    }
};

int main(int argc, char* argv[]) {
    Solution sol;
    std::vector<Interval> intervals = {{1, 4}, {2, 5}, {7, 9}};
    bool result = sol.canAttendAllAppointments(intervals);
    std::cout << "Can attend all appointments: " << result << std::endl;

    intervals = {{6, 7}, {2, 4}, {8, 12}};
    result = sol.canAttendAllAppointments(intervals);
    std::cout << "Can attend all appointments: " << result << std::endl;

    intervals = {{4, 5}, {2, 3}, {3, 6}};
    result = sol.canAttendAllAppointments(intervals);
    std::cout << "Can attend all appointments: " << result << std::endl;
}