/*
	shimon0505004
	146. LRU Cache
	https://leetcode.com/problems/lru-cache/
*/

class LRUCache {
public:
    using KeyValuePair = std::pair<int,int>;
    using LRUCacheList = std::list<KeyValuePair>;
    using LRUCacheListIterator = LRUCacheList::iterator;
    using LRUCacheMap = std::unordered_map<int,LRUCacheListIterator>;
    using LRUCacheMapIterator = LRUCacheMap::iterator;
    
    
    LRUCache(int capacity) {
        maxCapacity = capacity;
        currentSize = 0;
        lruCacheList.clear();
        map.clear();
    }
    
    int get(int key) 
    {
        int value = -1;
        if(map.find(key) != map.end())
        {
            LRUCacheListIterator iter = map[key];
            value = (*iter).second;
            if(iter != lruCacheList.begin())
                lruCacheList.splice(lruCacheList.begin(),lruCacheList, iter);
            
            map[key] = lruCacheList.begin();
        }
        return value;
    }
    
    void put(int key, int value) {

        if(map.find(key) != map.end())
        {
            LRUCacheListIterator iter = map[key];
            (*iter).second = value;
            if(iter != lruCacheList.begin())
                lruCacheList.splice(lruCacheList.begin(),lruCacheList, iter);            
        
            map[key] = lruCacheList.begin();
        }
        else
        {
            KeyValuePair pair = std::make_pair(key,value);
            lruCacheList.push_front(pair);
            currentSize++;
            map[key] = lruCacheList.begin();
        }                
        
        while(currentSize > maxCapacity)
        {
            LRUCacheListIterator lastItemIterator = std::prev(lruCacheList.end(), 1);
            int lastItemKey = (*lastItemIterator).first;
            map.erase(lastItemKey);
            lruCacheList.pop_back();
            currentSize--;
        }
        
    }
    
    
private:
    int maxCapacity;
    int currentSize;
    LRUCacheList lruCacheList;
    LRUCacheMap  map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */