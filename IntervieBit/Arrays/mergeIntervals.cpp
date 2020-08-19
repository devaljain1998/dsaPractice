#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct Solution {
    vector<Interval> insert(vector<Interval> &intervals, 
        Interval newInterval);
};

// Examples:
// 1.[1,3],[6,9] + [2,5] => [1,5],[6,9]
// 2. [1,2],[3,5],[6,7],[8,10],[12,16] + [4,9] => [1,2],[3,10],[12,16]

// PsuedoCode:
// newInterval
// Traverse Each Interval: until (PriorityQueue is empty)
// If any interval isOverlapping with newInterval:
// Pop the current Interval
// Merge both the intervals and get the new interval
// Again insert the intervals into the heap
// else:
// Append the interval into vector of intervals

// Condition for merging (a, b) and (c, d):
// (c >= a) && (c <= b)
// or (d >= a) && (d <= b)

//Utility Funcs:
void
displayVector(const vector<Interval> &intervals)
{
    cout << "V: ";
    for (auto interval: intervals) {
        cout << "(" << interval.start << ", " << interval.end << "), " << endl;
    }
    cout << endl;
}

//Creating Comparator for the Interval:
struct IntervalComparator
{
    bool operator()(const Interval& first, const Interval& second)
    {
        // return lhs < rhs;
        if (first.start != second.start) return first.start < second.start;
        else return first.end <= second.end;
    }
};

bool isIntervalsOverlapping(Interval a, Interval b) {
    bool overlap = ((b.start >= a.end) && (b.start <= a.end)) ||
           ((b.end >= a.end) && (b.end <= a.end));
           
    return overlap;
}

Interval mergeIntervals(Interval a, Interval b) {
    int start = min(a.start, b.start);
    int end = max(a.end, b.end);
    Interval newInterval(start, end);
    return newInterval;
}

void displayQueue(priority_queue <Interval, vector<Interval>, IntervalComparator> 
        intervalQueue) {
    vector<Interval> intervals;
    cout << "Q: ";
    
    while(intervalQueue.empty()) {
        intervals.push_back(intervalQueue.top());
        intervalQueue.pop();
    }
    
    return displayVector(intervals);
}

 
vector<Interval> Solution::insert(vector<Interval> &intervals, 
        Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    //Created a priority queue
    priority_queue <Interval, vector<Interval>, IntervalComparator> 
        intervalQueue;
        
    for (auto interval : intervals) {
        intervalQueue.push(interval);
    }
        
    //Creating a vector for solutions
    intervals.clear();
    
    displayVector(intervals);
    displayQueue(intervalQueue);
        
    while(intervalQueue.empty()) {
        displayQueue(intervalQueue);
        //Get a interval from queue:
        auto currentInterval = intervalQueue.top();
        
        if (isIntervalsOverlapping(currentInterval, newInterval)) {
            // Pop the current Interval
            intervalQueue.pop();
            // Merge both the intervals and get the new interval
            newInterval = mergeIntervals(currentInterval, newInterval);
        } else {
            // Append the interval into vector of intervals
            intervals.push_back(currentInterval);
        }
    }
    
    return intervals;
}

void test() {
    // A : [ (1, 2), (3, 6) ]
    // B : (10, 8)
    // O/P: (1, 2) (3, 6) (8, 10) 
    vector<Interval> intervals{
        Interval(1, 2),
        Interval(3, 6),
    };
    Interval newInterval(10, 8);
    vector<Interval> OUTPUTintervals{
        Interval(1, 2),
        Interval(3, 6),
        Interval(8, 10),
    };
    auto OPintervals = Solution().insert(intervals, newInterval);
    return;
}

int main() {
    test();
    return 0;
}