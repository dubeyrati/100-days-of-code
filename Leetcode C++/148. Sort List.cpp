class Solution {
    ListNode* splitList(ListNode *head) {
        ListNode dummy, *p = &dummy, *q = &dummy;
        dummy.next = head;
        while (q && q->next) {
            q = q->next->next;
            p = p->next;
        }
        auto next = p->next;
        p->next = NULL;
        return next;
    }
    ListNode *mergeList(ListNode *a, ListNode *b) {
        ListNode head, *tail = &head;
        while (a && b) {
            ListNode *node;
            if (a->val <= b->val) {
                node = a;
                a = a->next;
            } else {
                node = b;
                b = b->next;
            }
            tail->next = node;
            tail = node;
        }
        if (a) tail->next = a;
        if (b) tail->next = b;
        return head.next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        auto b = splitList(head);
        return mergeList(sortList(head), sortList(b));
    }
};