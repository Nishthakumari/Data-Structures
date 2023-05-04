//https://leetcode.com/problems/binary-tree-level-order-traversal/description/

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

    int height(TreeNode* root)
    {
        if(root==NULL) return 0;

        return 1+ max(height(root->left), height(root->right));
    }

    void printCurrentLevel(TreeNode* root, int level, vector<int> &v)
    {
        if(level ==1)
        {
            v.push_back(root->val);
        }

        if(root->left)
        printCurrentLevel(root->left, level-1, v);

        if(root->right)
        printCurrentLevel(root->right, level-1, v);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        
        int h = height(root);
        int i;
        for(int i=1;i<=h;i++)
        {
            vector<int> v;
            printCurrentLevel(root, i, v);
            ans.push_back(v);
        }

        return ans;
    }
};
