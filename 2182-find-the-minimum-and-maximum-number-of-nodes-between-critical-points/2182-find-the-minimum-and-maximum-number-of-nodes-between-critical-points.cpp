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
class Solution {
public:

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int prevIndex = -1, currIndex = 0, prevValue = head->val;
        int firstIndex = -1;
        ListNode* itr = head->next;
        vector<int>res = {INT_MAX, -1};
        
        while(itr->next) {

            if((prevValue < itr->val && itr->next->val < itr->val) ||
                    (prevValue > itr->val && itr->next->val > itr->val)) {
                
                if(prevIndex != -1) {
                    res[0] = min(res[0], currIndex - prevIndex);    
                }
                if(firstIndex != -1) {
                    res[1] = currIndex - firstIndex;
                }
                else{
                    firstIndex = currIndex;
                }
                prevIndex = currIndex;
                
            }
            prevValue = itr->val;
            itr = itr->next;
            currIndex++;
        }

        if(res[0] == INT_MAX) {
            res[0] = -1;
            res[1] = -1;
        }
        return res;
    }
};