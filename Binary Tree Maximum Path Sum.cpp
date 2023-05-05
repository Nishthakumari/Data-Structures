//https://www.youtube.com/watch?v=JBYs5J4skZE
//https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

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

    int findmaxpath(TreeNode* root, int &ans)
    {
        if(!root) return 0;
        int left = findmaxpath(root->left, ans);
        int right = findmaxpath(root->right, ans);

        int straightpath = max(root->val, max(left+root->val, right+root->val));
        int curvedpath = root->val+left+right;
        ans =max(ans,  max(straightpath, curvedpath));
        return straightpath;

    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        findmaxpath(root, ans);
        return ans;
    }
};
