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

//iterative solution for printing the post order traversal
class Solution {
public:

    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int>arr;
        if(!root)return arr;
        stack<TreeNode*>st; 
        TreeNode* node = root;

        while(node != nullptr || !st.empty()) {
            if(node != nullptr) {
                arr.push_back(node->val);
                st.push(node);
                node = node->right;
            }else {
                node = st.top();
                st.pop();
                node = node->left;
            }
        }

        reverse(arr.begin(), arr.end());

        return arr;
    }
};