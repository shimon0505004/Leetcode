/*
	https://leetcode.com/problems/merge-sorted-array/
	shimon0505004
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m);
        nums2.resize(n);
        vector<int>::iterator currentIter = nums1.begin();
        int mCounter =0;
        while(!nums2.empty() && currentIter!=nums1.end())
        {
            if(nums2.front()<=*currentIter)
            {
                
                currentIter= nums1.insert(currentIter,nums2.front());
                nums2.erase(nums2.begin());
            }
            currentIter=std::next(currentIter);
            mCounter++;
        }
        
        while(!nums2.empty())
        {
           nums1.push_back(nums2.front());
            nums2.erase(nums2.begin());
        }
    }
};