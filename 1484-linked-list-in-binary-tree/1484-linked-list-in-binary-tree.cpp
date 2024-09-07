/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

    bool res = false;

    bool dfs(ListNode* head, TreeNode* root, ListNode* curr) {
        if(curr == nullptr)return true;

        if(root == nullptr)return false;
        

        if(curr->val == root->val) {
            if(dfs(head, root->left, curr->next))return true;
            if(dfs(head, root->right, curr->next))return true;
        }
        
        if(curr != head) return false;

        if(dfs(head, root->left, head))
            return true;
        
        return dfs(head, root->right, head);
        
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head, root, head);
    }
};