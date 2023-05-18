https://leetcode.com/problems/binary-tree-inorder-traversal/description/

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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> inorder;
        inorderHelper(root, inorder);
        return inorder;
    }
    
    void inorderHelper(TreeNode* root, vector<int> & inorder)
    {
        if(root==NULL)
            return;
        
        
        inorderHelper(root->left, inorder);
        inorder.push_back(root->val);
        inorderHelper(root->right, inorder);
    }
    
    
    
    
};
