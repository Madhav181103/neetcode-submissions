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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1)return head;
        ListNode* temp = head ;
        for(int i = 0 ;i < k ; i++){
            if(!temp)return head;
            temp = temp->next;
        }
        int count = 0 ;
        ListNode* prev = nullptr ;
        ListNode* nextnode = nullptr ;
        ListNode* curr = head ;
        while(count<k && curr){
            nextnode = curr->next ;
            curr->next = prev ;
            prev = curr ;
            curr = nextnode ;
            count++;
        }

        head->next = reverseKGroup(temp,k);
        return prev; 
    }
};
