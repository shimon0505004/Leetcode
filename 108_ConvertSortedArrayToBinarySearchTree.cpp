/*
	https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
	shimon0505004
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return nullptr;
        else if(nums.size()==1)
            return new TreeNode(nums.at(0));
        else
        {
            int midIndex = nums.size()/2;
            TreeNode* mid = new TreeNode(nums.at(midIndex));
            vector<int> lo = vector<int>(nums.begin(),nums.begin()+midIndex);
            vector<int> hi = vector<int>(nums.begin()+midIndex+1,nums.end());
            mid->left = sortedArrayToBST(lo);
            mid->right = sortedArrayToBST(hi);
            return mid;
        }
    }
};