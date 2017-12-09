/*
	https://leetcode.com/problems/arithmetic-slices/
	shimon0505004
*/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int sliceCount = 0;
                
        for(int index=0;index<A.size();)
        {
            bool sliceFound = false;
            int currentSliceSize = 3;
            while((index+currentSliceSize)<=A.size())
            {   
                if(A.at(index+currentSliceSize-1)-A.at(index+currentSliceSize-2) 
                    != A.at(index+currentSliceSize-2)- A.at(index+currentSliceSize-3))
                        break;
                else if(currentSliceSize==3)
                    sliceFound = true;
                       
                currentSliceSize++;
            }
             
            if(currentSliceSize>3)
                currentSliceSize--;

            
            if(sliceFound)
            {
                int currentSliceCount = (((currentSliceSize-2)*(currentSliceSize-1))/2);
                sliceCount += currentSliceCount;
                index += currentSliceSize;
            }
            else
                index++;
            

        }
        
        return sliceCount;
    }
    
    
};