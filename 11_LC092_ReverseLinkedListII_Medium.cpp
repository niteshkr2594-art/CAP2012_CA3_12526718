class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || left == right){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;

        for(int i = 1; i < left; i++){
            prev = curr;
            curr = curr->next;
        }
        ListNode* before = prev;
        ListNode* first = curr;

        ListNode* nex = NULL;

        for(int i = 0; i < right - left + 1; i++){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        if(before != NULL){
            before->next = prev;
        }
        else{
            head = prev;
        }
        first->next = curr;

        return head;
    }
};
 