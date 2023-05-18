https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        if(nums.size()==0)
            return NULL;
        TreeNode* head=helper(nums,0,nums.size()-1);
        return head;
        
        
    }
    
    TreeNode* helper(vector<int> &nums, int l, int h)
    {

    if(l>h) return NULL;
        
        int m=(l+(h-l)/2);
        TreeNode *node= new TreeNode(nums[m]);
        node->left= helper(nums, l, m-1);
        node->right= helper(nums, m+1,h);
        return node;
        
    }
    
    
};
