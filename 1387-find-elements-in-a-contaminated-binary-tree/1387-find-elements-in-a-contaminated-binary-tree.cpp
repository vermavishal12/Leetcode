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
class FindElements {

private: 
    unordered_map<int , bool> map;
    void recoverTree(TreeNode* root, int currValue) {
        map[currValue] = true;
        if(root->left != nullptr) {
            recoverTree(root->left, currValue*2 + 1);
        }

        if(root->right != nullptr) {
            recoverTree(root->right, currValue*2 + 2);
        }
    }

public:

    FindElements(TreeNode* root) {
        if(root != nullptr)
            recoverTree(root, 0);
    }
    

    bool find(int target) {
        return map[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */