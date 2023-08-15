class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;
            
        ListNode *p1 = head, *p2 = head, *prev1 = head, *prev2 = head;
        int len = 0;
        while(p1 != NULL){
            len++;
            p1 = p1->next;
        }
        k = k % len;
        if(k==0)    return head;
        p1 = head;

        while(k-- && p1!= NULL){
            p1 = p1->next;
        }

        while(p1 != NULL){
            prev1 = p1;
            prev2 = p2;

            p1 = p1->next;
            p2 = p2->next;
        }

        prev1->next = head;
        prev2->next = NULL;
        return p2;
    }
};
