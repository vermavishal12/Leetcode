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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int size = 0;
        ListNode* curr = head;
        
        // count the total length of the linked list
        while(curr){
            size++;
            curr = curr->next;
        }
        // counting the container size and the number of containers which will contain 
        // one extra nodes than others
        int cntnrSize = size/k, xtra = size%k;

        curr = head;
        int itr = 0;
        ListNode* prev = curr;

        vector<ListNode*>res(k, nullptr);

        // filling the each container we will iterate through the loop
        for(int i = 0; i < k ; i++) {
            // set the container head
            res[i] = curr;

            int currSize = cntnrSize ;
            // will calculate the size of the current container 
            if(xtra > 0){
                currSize++;
                xtra--;
            }

            while(itr < currSize) {
                prev = curr;
                if(curr != nullptr) {
                    curr = curr->next;
                }
                itr++;
            }
            itr = 0;

            // set the last node of the current container as tail
            if(prev != nullptr){
                prev->next = nullptr;
            }
        
        }
        return res;
    }
};