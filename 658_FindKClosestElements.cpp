/*
	https://leetcode.com/problems/find-k-closest-elements/
	shimon0505004
*/


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int nearestIndex = findNearestIndex(arr,x);
        return findClosestElementsUsingNearestIndexOfX(arr, k, x, nearestIndex);        
    }
    
    
private:    
    vector<int> findClosestElementsUsingNearestIndexOfX(vector<int>& arr, int k, int x, int nearestIndex)
    {
        vector<int> result;
        if(k>0)
        {
            int minIndex = std::max(0,nearestIndex-(k-1));

            int maxIndex = std::min(nearestIndex+(k-1),static_cast<int>(arr.size()-1));

            cout << minIndex << " " << maxIndex << endl;
            result = vector<int>(arr.begin()+minIndex,arr.begin()+maxIndex+1);
            while(result.size()>k)
            {
                if(x-arr.at(minIndex) > arr.at(maxIndex)-x)
                {
                    result.erase(result.begin());
                    minIndex++;
                }
                else
                {
                    result.pop_back();
                    maxIndex--;
                }
            }
        }
        return result;
    }
    
    
    int findNearestIndex(vector<int>& arr, int x)
    {
        //This either finds index of x in arr, or finds the index of the element nearest to the hole.
        int low = 0;
        int high = arr.size()-1;
        int nearestIndex = -1;
        while(low<=high && low<arr.size() && high >=0)
        {
            int mid = (low+high)/2;
            if(x > arr.at(mid))
                low = mid + 1;
            else if (x< arr.at(mid))
                high = mid - 1;
            else
            {
                nearestIndex = mid;
                break;
            }
        }

        
        if(nearestIndex==-1)
            nearestIndex = std::min(low,high);
        nearestIndex = std::max(0,nearestIndex);
        nearestIndex = std::min(static_cast<int>(arr.size()-1), nearestIndex);
        return nearestIndex;
    }
};