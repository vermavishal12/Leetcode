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

    int leftHeight(TreeNode* root) {
        TreeNode* node = root;
        int curr = 0;
        while(node) {
            curr++;
            node = node->left;
        }
        return curr;
    }

    int rightHeight(TreeNode* root) {
        TreeNode* node = root;
        int curr = 0;
        while(node) {
            curr++;
            node = node->right;
        }
        return curr;
    }

    int countNodes(TreeNode* root) {
        if(root==nullptr)return 0;
        int leftH = leftHeight(root);
        int rightH = rightHeight(root);
        if(left == right)return pow(2, rightH) -1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};