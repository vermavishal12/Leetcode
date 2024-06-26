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

    vector<int>arr;

    void func(TreeNode* root) {
        if(root == nullptr)return;

        func(root->left);
        arr.push_back(root->val);
        func(root->right);
    }

    TreeNode* createTree(int left, int right) {
        if(left > right)return nullptr;
        int mid = left + (right-left)/2;

        if(left == right) {
            TreeNode* newNode = new TreeNode(arr[mid]);
            return newNode;
        }
        
        

        TreeNode* newNode = new TreeNode(arr[mid],nullptr,nullptr);
        newNode->left = createTree(left, mid-1);
        newNode->right = createTree(mid+1, right);
        return newNode;
        
    }

    TreeNode* balanceBST(TreeNode* root) {
        func(root);

        return createTree(0, arr.size()-1);    
    }
};