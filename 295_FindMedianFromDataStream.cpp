/*
	https://leetcode.com/problems/find-median-from-data-stream/
	shimon0505004
*/

#include<priority_queue>
#include<functional>

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(maxHeap_forLeftHalf.empty())
        {
            maxHeap_forLeftHalf.push(num);
        }
        else
        {
            if(num>=maxHeap_forLeftHalf.top())
                minHeap_forRightHalf.push(num);
            else
                maxHeap_forLeftHalf.push(num);
            
            if(maxHeap_forLeftHalf.size()>minHeap_forRightHalf.size()+1)
            {
                minHeap_forRightHalf.push(maxHeap_forLeftHalf.top());
                maxHeap_forLeftHalf.pop();
            }
            else if(minHeap_forRightHalf.size()>maxHeap_forLeftHalf.size()+1)
            {
                maxHeap_forLeftHalf.push(minHeap_forRightHalf.top());
                minHeap_forRightHalf.pop();
            }
        }
    }
    
    double findMedian() {
        double median;
        if(maxHeap_forLeftHalf.size()>minHeap_forRightHalf.size())
            median = (static_cast<double>(maxHeap_forLeftHalf.top()));
        else if(maxHeap_forLeftHalf.size()<minHeap_forRightHalf.size())
            median = (static_cast<double>(minHeap_forRightHalf.top()));
        else
            median = (static_cast<double>(maxHeap_forLeftHalf.top())+(static_cast<double>(minHeap_forRightHalf.top())))/2;
        return median;
    }
    
    
private:
    std::priority_queue<int> maxHeap_forLeftHalf;
    std::priority_queue<int,vector<int>,std::greater<int>> minHeap_forRightHalf;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */