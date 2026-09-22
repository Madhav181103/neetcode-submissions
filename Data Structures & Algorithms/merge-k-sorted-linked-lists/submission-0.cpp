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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct cmp{
            bool operator() (ListNode* a , ListNode* b)  {
                return a->val > b->val;
            }
        };
        priority_queue <ListNode* , vector<ListNode*> ,cmp> pq; 
        for(auto node : lists){
            if(node)pq.push(node);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy ;
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            temp->next  = node ;
            temp = temp->next;
            if(node->next)pq.push(node->next);
        }
        return dummy->next;
    }
};