//https://leetcode.com/problems/subtree-of-another-tree/description/

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

bool isMatch(TreeNode* node1, TreeNode* node2)
{
    if(node1==NULL && node2==NULL) return true;

    if(node1==NULL || node2==NULL) return false;

    return (node1->val==node2->val) && (isMatch(node1->left, node2->left)) && (isMatch(node1->right, node2->right));


}


public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(root==NULL && subRoot==NULL)  return true;

        if(root==NULL) return false;

        return (isSubtree(root->left, subRoot))|| isMatch(root, subRoot)|| (isSubtree(root->right, subRoot));


    }
};
