//https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

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
    int ans;
      void inorder(TreeNode* node, int &k)
    {
        if(node==NULL) return;

        inorder(node->left, k);
        k--;

        if(k==0)
        {
            ans = node->val;
            return;
        }

          inorder(node->right, k);


    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }

  
};
