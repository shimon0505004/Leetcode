/*
	shimon0505004
	146. LRU Cache
	https://leetcode.com/problems/lru-cache/
*/



class LRUCache {
public:
    using LRUCacheList = std::list<std::pair<int,int>>;
    using LRUCacheIterator = LRUCacheList::iterator;    
    using LRUCacheMap = std::unordered_map<int,LRUCacheIterator>;
    using LRUCacheMapIterator = std::unordered_map<int,LRUCacheIterator>::iterator;
    
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->currentSize = 0;
        existingKeys.clear();
        lruCache.clear();
    }
    
    int get(int key) {
        if(!existingKeys.empty())
        {
            LRUCacheMapIterator lruMapIterator = existingKeys.find(key);
            if(lruMapIterator != existingKeys.end())
            {
                LRUCacheIterator lruCacheIterator = existingKeys[key];
                if(lruCacheIterator!= lruCache.begin())
                {
                    lruCache.splice(lruCache.begin(), lruCache, lruCacheIterator);
                    existingKeys[key] = lruCache.begin();
                }
                
                return (*(existingKeys[key])).second;
            }
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
        LRUCacheMapIterator lruMapIterator = existingKeys.find(key);
        if(lruMapIterator != existingKeys.end())
        {
            LRUCacheIterator lruCacheIterator = existingKeys[key];
            if(lruCacheIterator!= lruCache.begin())
            {
                lruCache.splice(lruCache.begin(), lruCache, lruCacheIterator);
                existingKeys[key] = lruCache.begin();
            }
            (*(existingKeys[key])).second = value;
        }
        else
        {
            lruCache.push_front(std::make_pair(key,value));
            existingKeys[key] = lruCache.begin();
            currentSize++;
        }
        
        while(currentSize > capacity)
        {
            LRUCacheIterator lastElement = std::prev(lruCache.end(), 1);
            int lastElementKey = (*lastElement).first;
            existingKeys.erase (lastElementKey);
            lruCache.pop_back();
            currentSize--;
        }

    }
    
private:
    int capacity;
    int currentSize;
    LRUCacheMap existingKeys;
    LRUCacheList lruCache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */