/*
	shimon0505004
	692. Top K Frequent Words
	https://leetcode.com/problems/top-k-frequent-words/
*/

class Solution {
public:
    

    
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        std::set<string> uniqueWords;
        std::map<string,int> countmap;
        
        for(auto& word: words)
        {
            uniqueWords.insert(word);
            if(countmap.find(word)==countmap.end())
                countmap.insert(std::make_pair(word,1));                
            else
                countmap.at(word) = countmap.at(word)+1;                
        }
                
        std::vector<string> frequentList;
        frequentList.assign(uniqueWords.begin(),uniqueWords.end());
        
        auto Func = [&countmap](const string& left,const string& right){
            
            if(countmap.at(left) == countmap.at(right))
            {
                std::cout << left << " " << right << " " <<(left>right) << std::endl;
                return left > right;                
            }
            return countmap.at(left) < countmap.at(right) ;
        };
        
        std::make_heap(frequentList.begin(),frequentList.end(),Func);
        
        
        std::vector<string> result;
        result.reserve(k);
        
        for(int count = 0; count < k; count++)
        {
            result.emplace_back(frequentList.front());
            std::pop_heap(frequentList.begin(),frequentList.end(),Func);
            frequentList.pop_back();
        }
        
        
        return result;
    }
};