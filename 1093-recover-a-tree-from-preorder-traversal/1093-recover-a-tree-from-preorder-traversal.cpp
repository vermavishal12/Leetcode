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
    TreeNode* recoverFromPreorder(string traversal) {
        unordered_map<int,TreeNode*> treeMap;

        int currCount = 0;
        TreeNode* dummyNode = new TreeNode(0);
        treeMap[0] = dummyNode;        

        int i = 0, currNum = 0;
        while(i < traversal.size()) {
            currNum = 0;
            while(i < traversal.size() && traversal[i] != '-') {
                currNum = currNum*10 + (traversal[i++]-'0');
            }
            TreeNode* parent = treeMap[currCount];
            TreeNode* newNode = new TreeNode(currNum);
    
            if(parent->left == nullptr) {
                parent->left = newNode;
            } else if (parent->right == nullptr) {
                parent->right = newNode;
            }
            treeMap[currCount+1] = newNode;
            
            currCount = 0;
            while(i < traversal.size() && traversal[i] == '-') {
                currCount++;
                i++;
            }

        }
        return dummyNode->left;
    }
};