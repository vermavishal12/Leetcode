#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution{
    public: 
        ListNode* mergeNodes(ListNode* head) {
            int curr = 0;

            
            ListNode* newHead = new ListNode(-1);
            ListNode* itr = head, *ptr = itr;
            while(!itr) {
                if(itr->val == 0) {
                    if(curr != 0) {
                        ListNode* newNode = new ListNode(curr);
                        ptr->next = newNode;
                        ptr = newNode;
                    }
                }else{
                    curr += itr->val;
                }
            }
        }

        return ;
}