class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newnode = reverse(slow->next);
        slow->next = nullptr;

        ListNode* curr1 = head;
        ListNode* curr2 = newnode;

        while (curr1 && curr2) {
            ListNode* next1 = curr1->next;
            ListNode* next2 = curr2->next;

            curr1->next = curr2;
            curr2->next = next1;

            curr1 = next1;
            curr2 = next2;
        }
    }
};