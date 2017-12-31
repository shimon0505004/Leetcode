/*
	shimon0505004
	346. Moving Average from Data Stream
	https://leetcode.com/problems/moving-average-from-data-stream
*/

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        maxSlidingWindowSize = size;
        slidingWindow.clear();
    }
    
    double next(int val) {
        if(maxSlidingWindowSize == 0)
            return 0.0;
        
        if(slidingWindow.size() == maxSlidingWindowSize)
            slidingWindow.pop_front();
        
        slidingWindow.push_back(static_cast<double>(val));
        int currentSize = slidingWindow.size();
        double initialSum = 0 ;
        return (std::accumulate(slidingWindow.begin(),slidingWindow.end(), initialSum) / currentSize);
    }

private:
    std::list<double> slidingWindow;
    int maxSlidingWindowSize;
    int currentSlidingWindowSize;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */