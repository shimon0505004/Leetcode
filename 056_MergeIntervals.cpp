/*
	https://leetcode.com/problems/merge-intervals/
	shimon0505004
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        std::sort(intervals.begin(),intervals.end(),[](const Interval& l, const Interval& r){
           if(l.start==r.start)
               return l.end<r.end;
            
            return l.start<r.start;
        });

        vector<Interval> result;

        if(intervals.size()>0)
        {
            Interval current = intervals.front();
            intervals.erase(intervals.begin());
            while(!intervals.empty())
            {
                if((intervals.front().start>= current.start && intervals.front().start <= current.end)
                    || (intervals.front().end>= current.start && intervals.front().end <= current.end))
                {
                    current.start = std::min(current.start,intervals.front().start);
                    current.end = std::max(current.end,intervals.front().end);
                }
                else
                {
                    result.push_back(current);
                    current = intervals.front();
                }
 
                intervals.erase(intervals.begin());
            }
            
            result.push_back(current);
        }
        
        
        return result;
    }
};