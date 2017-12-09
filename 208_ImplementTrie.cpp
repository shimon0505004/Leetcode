/*
	https://leetcode.com/problems/implement-trie-prefix-tree/
	shimon0505004
*/

class TrieNode
{
public:    
    TrieNode()
        :isLeaf(false)
    {
        for(auto& child:children)
            child=nullptr;
    }
    
    
    bool isLeaf;
    TrieNode* children[26];
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
            int index = character-'a';
            if(node->children[index]==nullptr)
                node->children[index] = new TrieNode();
            
            node = node->children[index];
        }
        node->isLeaf=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for(const char& character : word)
        {
            int index = character-'a';
            if(node->children[index]!=nullptr)
                node = node->children[index];
            else
                return false;            
        }
        return node->isLeaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(const char& character : prefix)
        {
            int index = character-'a';
            if(node->children[index]!=nullptr)
                node = node->children[index];
            else
                return false;            
        }
        return true;
    }
    
private:
    TrieNode* root;
    
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */