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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,bool>map;
        // creating the map which will help to check the node value does contain in the hash set in the constant time
        for(auto& num: nums){
            map[num]= true;  
        }

        // this is the temperary head, this node does not have any significance with the resultant listnode;
        ListNode* tempHead = new ListNode(-1);

        // marking the temp head node as the predecessor of head node
        tempHead->next = head;

        // currNode = iterator for moving through the linked list and prev = previous node to current iterator node
        ListNode* currNode = head; 
        ListNode* prev = tempHead ;

        while(currNode) {
            // if the current node value is in the hash set, then we will skip the current node by marking the next node of the previous node to the next node of current node, 
            // else we mark the prev as currentNode for the next iteration 
            if(map[currNode->val]){
                prev->next = currNode->next;

            }else {
                prev = currNode;
            }
            currNode = currNode->next;
        }
        // returning the head node
        return tempHead->next;


    }
};