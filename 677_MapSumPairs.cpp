/*
	https://leetcode.com/problems/map-sum-pairs/
	shimon0505004
*/

class TrieNode
{
public:    
    TrieNode()
        :isWord(false)
    {
        for(auto& child:children)
            child=nullptr;
    }
    
    bool isWord;
    TrieNode* children[256];
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for(const char& character : word)
        {
            int index = character-0;
            if(node->children[index]==nullptr)
                node->children[index] = new TrieNode();
            
            node = node->children[index];
        }
        node->isWord=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for(const char& character : word)
        {
            int index = character-0;
            if(node->children[index]!=nullptr)
                node = node->children[index];
            else
                return false;            
        }
        return node->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(const char& character : prefix)
        {
            int index = character-0;
            if(node->children[index]!=nullptr)
                node = node->children[index];
            else
                return false;            
        }
        return true;
    }
    
    set<string> wordsThatStartsWith(string prefix)
    {
        TrieNode* node = root;
        set<string> wordList;
        for(const char& character : prefix)
        {
            int index = character-0;
            if(node->children[index]!=nullptr)
                node = node->children[index];
            else
                return wordList;            
        }
        
        std::stack<std::pair<TrieNode*,string>> s;
        if(node!=nullptr)
        {
            s.push(std::make_pair(node,prefix));
            while(!s.empty())
            {
                std::pair<TrieNode*,string> nodeStringPair = s.top();
                s.pop();
                if(nodeStringPair.first->isWord)
                    wordList.emplace(nodeStringPair.second);
                
                for(int index=0;index<256 ;index++)
                {
                    TrieNode* child = nodeStringPair.first->children[index];
                    if(child!=nullptr)
                    {
                        string childStr = nodeStringPair.second;
                        childStr += ((char)(index));
                        s.push(std::make_pair(child,childStr));
                    }
                }
            }
        }
        
        return wordList;
    }
    
    
    
private:
    TrieNode* root;
    
};




class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        trieForKeys = new Trie();
        mapOfInt.clear();
    }
    
    void insert(string key, int val) {
        trieForKeys->insert(key);
        if(mapOfInt.count(key)==0)
            mapOfInt.emplace(key,val);
        else
            mapOfInt.at(key) = val;
    }
    
    int sum(string prefix) {
        int result=0;
        for(const string& key: trieForKeys->wordsThatStartsWith(prefix))
            result += mapOfInt[key];
        
        return result;
    }
    
private:
    Trie* trieForKeys;
    std::map<string,int> mapOfInt;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */